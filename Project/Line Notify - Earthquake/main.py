from firebase_admin import credentials
import firebase_admin
from firebase_admin import firestore

import requests


#### Initialization ####
## 中央氣象署 API ##
cwa_token = "CWA-54E742AA-901E-45B0-84E1-42EF6CE8FFA8"
# 地震 API
earthquake_url = f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/E-A0015-001?Authorization={cwa_token}&format=JSON"

# Firestore API
cred = credentials.Certificate("serviceAccount.json")
firebase_admin.initialize_app(cred)
db = firestore.client()
doc_ref = db.collection("line-notify-earthquake").document("earthquake")

# Line Notify API
line_notify_token = "gA7LycwcrixzzpJKomSZNGS4jTL5W3PjTSrrUILT01O"
line_notify_url = "https://notify-api.line.me/api/notify"

headers = {"Authorization": f"Bearer {line_notify_token}"}


# 部署在Cloud Functions
def main(request):
    #### Earthquake ####
    data = requests.get(earthquake_url).json()["records"]["Earthquake"]

    # Firestore抓取資料，判斷這則地震訊息是否已經發送過
    doc_data = doc_ref.get().to_dict()
    if doc_data is not None and doc_data["pre_number"] == data[0]["EarthquakeNo"]:
        return "Message has been sent."

    # 避免5分鐘內發生多次地震，導致只發送最接近的一次地震
    for i in range(data[0]["EarthquakeNo"] - doc_data["pre_number"] - 1, -1, -1):  # type: ignore
        current_data = data[i]

        ### 處理訊息 ###
        # 地震編號
        number = current_data["EarthquakeNo"]

        ## EarthquakeInfo ##
        earthquake_info = current_data["EarthquakeInfo"]

        # 發震日期
        date, time = earthquake_info["OriginTime"].split(" ")
        date = date.split("-")
        time = time.split(":")

        # 震央位置
        latitude = earthquake_info["Epicenter"]["EpicenterLatitude"]
        longitude = earthquake_info["Epicenter"]["EpicenterLongitude"]

        # 震源深度
        focal_depth = earthquake_info["FocalDepth"]

        # 芮氏規模
        magnitude = earthquake_info["EarthquakeMagnitude"]["MagnitudeValue"]

        # 相對位置
        location = earthquake_info["Epicenter"]["Location"]

        message = {
            "message": f"""
地震編號：第{number}號
發震時間：{int(date[0]) - 1911}年{date[1]}月{date[2]}日{time[0]}時{time[1]}分{time[2]}秒
震央位置：北緯{latitude}°   東經{longitude}°
震源深度：{focal_depth}公里
芮氏規模：{magnitude}
相對位置：{location}
"""
        }

        ## ShakingArea ##
        shaking_area = sorted(
            current_data["Intensity"]["ShakingArea"],
            key=lambda x: x["AreaIntensity"],
            reverse=True,
        )

        message["message"] += "最大震度級\n"
        for area in shaking_area:
            if "最大震度" not in area["AreaDesc"]:
                message[
                    "message"
                ] += f"● {area['AreaDesc']} 最大震度 {area['AreaIntensity']}"

                pre_intensity = 0
                first = True
                for eq_station in area["EqStation"]:
                    if pre_intensity != eq_station["SeismicIntensity"]:
                        message["message"] += f"\n   {eq_station['SeismicIntensity']}："

                        pre_intensity = eq_station["SeismicIntensity"]
                        first = True

                    if first is False:
                        message["message"] += "、"
                    message["message"] += f"{eq_station['StationName']}"

                    first = False

                message["message"] += "\n"

        ### 加入圖片 ###
        message["imageThumbnail"] = current_data["ReportImageURI"]
        message["imageFullsize"] = current_data["ReportImageURI"]

        #### Line Notify ####
        # 發送訊息
        requests.post(line_notify_url, headers=headers, data=message)

    # Firestore儲存資料
    doc_ref.set(
        {
            "pre_number": number,
            "pre_time": f"{int(date[0]) - 1911}/{date[1]}/{date[2]} {time[0]}:{time[1]}:{time[2]}",
        }
    )

    return "OK"
