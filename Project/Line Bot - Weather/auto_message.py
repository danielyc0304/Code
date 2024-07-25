from firebase_admin import credentials, firestore
import firebase_admin

import requests
import json


### Initialization ###
## 中央氣象署 API ##
cwa_token = "CWA-54E742AA-901E-45B0-84E1-42EF6CE8FFA8"
# 天氣特報-各別天氣警特報之內容及所影響之區域 API
weather_news_url = f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/W-C0033-002?Authorization={cwa_token}"

## Firestore API ##
cred = credentials.Certificate("serviceAccount.json")
firebase_admin.initialize_app(cred)
db = firestore.client()

rain_ref = db.collection("line-bot-weather").document("rain")
typhoon_ref = db.collection("line-bot-weather").document("typhoon")
wind_ref = db.collection("line-bot-weather").document("wind")

## Line Bot API ##
channel_access_token = "Vs4TxhGvoovBwRk6IOWB8sWS3sCiGlg2t36+d11xb8ZY2P0dzGQh/rFuGyWmyV9EEenVM9RzrjdPx8E5FRCVxL1z0USJHyYpdCx9RzZcLt1LwX9yvwfwwhKrLoE4Bwyb7MwY1AzCjXcdBvFhWCvv6wdB04t89/1O/w1cDnyilFU="

headers = {
    "Content-Type": "application/json",
    "Authorization": f"Bearer {channel_access_token}",
}


# 部署在Cloud Functions
def main(request):
    data = requests.get(weather_news_url).json()["records"]["record"]

    for news in data:
        if (
            "雨"
            in news["hazardConditions"]["hazards"]["hazard"][0]["info"]["phenomena"]
        ):
            rain_data = rain_ref.get().to_dict()
            if (
                rain_data is None
                or rain_data["issue_time"] != news["datasetInfo"]["issueTime"]  # type: ignore
            ):
                body = {
                    "messages": [
                        {
                            "type": "text",
                            "text": f"""【自動推播訊息】
⚠️{news['datasetInfo']['datasetDescription']}⚠️
發佈時間：{news['datasetInfo']['issueTime']}

{news['contents']['content']['contentText'].strip()}""",
                        }
                    ]
                }
                requests.post(
                    "https://api.line.me/v2/bot/message/broadcast",
                    headers=headers,
                    data=json.dumps(body),
                )

                rain_ref.set({"issue_time": news["datasetInfo"]["issueTime"]})

        elif (
            "颱風"
            in news["hazardConditions"]["hazards"]["hazard"][0]["info"]["phenomena"]
        ):
            typhoon_data = typhoon_ref.get().to_dict()
            if (
                typhoon_data is None
                or typhoon_data["issue_time"] != news["datasetInfo"]["issueTime"]  # type: ignore
            ):
                body = {
                    "messages": [
                        {
                            "type": "text",
                            "text": f"""【自動推播訊息】
⚠️{news['datasetInfo']['datasetDescription']}⚠️
發佈時間：{news['datasetInfo']['issueTime']}

{news['contents']['content']['contentText'].strip()}""",
                        }
                    ]
                }
                requests.post(
                    "https://api.line.me/v2/bot/message/broadcast",
                    headers=headers,
                    data=json.dumps(body),
                )

                typhoon_ref.set({"issue_time": news["datasetInfo"]["issueTime"]})

        elif (
            "風"
            in news["hazardConditions"]["hazards"]["hazard"][0]["info"]["phenomena"]
        ):
            wind_data = wind_ref.get().to_dict()
            if (
                wind_data is None
                or wind_data["issue_time"] != news["datasetInfo"]["issueTime"]  # type: ignore
            ):
                body = {
                    "messages": [
                        {
                            "type": "text",
                            "text": f"""【自動推播訊息】
⚠️{news['datasetInfo']['datasetDescription']}⚠️
發佈時間：{news['datasetInfo']['issueTime']}

{news['contents']['content']['contentText'].strip()}""",
                        }
                    ]
                }
                requests.post(
                    "https://api.line.me/v2/bot/message/broadcast",
                    headers=headers,
                    data=json.dumps(body),
                )

                wind_ref.set({"issue_time": news["datasetInfo"]["issueTime"]})

    return "OK"
