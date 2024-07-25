import json
import requests


#### Initialization ####
### Line Bot API ###
channel_access_token = "Vs4TxhGvoovBwRk6IOWB8sWS3sCiGlg2t36+d11xb8ZY2P0dzGQh/rFuGyWmyV9EEenVM9RzrjdPx8E5FRCVxL1z0USJHyYpdCx9RzZcLt1LwX9yvwfwwhKrLoE4Bwyb7MwY1AzCjXcdBvFhWCvv6wdB04t89/1O/w1cDnyilFU="

### 中央氣象署 API ###
cwa_token = "CWA-54E742AA-901E-45B0-84E1-42EF6CE8FFA8"

## Forecast ##
# 一般天氣預報-分區天氣小幫手 API
weather_forecast_url = [
    "https://opendata.cwa.gov.tw/fileapi/v1/opendataapi/",
    f"?Authorization={cwa_token}&downloadType=WEB&format=JSON",
]
# 一般天氣預報-今明36小時天氣預報 API
weather_forecast_details_url = f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/F-C0032-001?Authorization={cwa_token}&locationName="

## Current ##
weather_now_urls = [
    f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/O-A0003-001?Authorization={cwa_token}&StationId=",  # 現在天氣觀測報告-氣象觀測資料 API
    f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/O-A0001-001?Authorization={cwa_token}&StationId=",  # 自動氣象站-氣象觀測資料 API
]

## 地震 API ##
earthquake_url = f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/E-A0015-001?Authorization={cwa_token}&format=JSON"


# 部署在Cloud Functions
def main(request):
    request_body = request.get_data(as_text=True)
    request_data = json.loads(request_body)

    reply_token = request_data["events"][0]["replyToken"]

    # 我不會用messaging.MessagingApi.reply_message
    headers = {
        "Content-Type": "application/json",
        "Authorization": f"Bearer {channel_access_token}",
    }
    body = {
        "replyToken": reply_token,
        "messages": generate_messages(request_data),
    }
    requests.post(
        "https://api.line.me/v2/bot/message/reply",
        headers=headers,
        data=json.dumps(body),
    )

    return "OK"


def generate_messages(data):
    #### 天氣預報 ####
    if data["events"][0]["message"]["type"] == "location":
        # 整理資料
        station_id = json.load(open("stationId.json"))
        address = data["events"][0]["message"]["address"]
        county_id = json.load(open("countyId.json"))

        # 尋找所在縣市
        find_forecast, find_current = False, False
        message_current = ""
        for station in station_id:
            if (
                station["County"] in address.replace("台", "臺")
                and find_forecast is False
            ):
                ## 概況 ##
                weather_forecast_data = json.loads(
                    requests.get(
                        county_id[station["County"]].join(weather_forecast_url)
                    ).text
                )["cwaopendata"]["dataset"]["parameterSet"]["parameter"]

                overviews = [
                    forecast["parameterValue"]
                    for forecast in weather_forecast_data[1:3]
                    if "昨" not in forecast["parameterValue"]
                ]

                ## 詳細預報數據 ##
                weather_forecast_details_data = json.loads(
                    requests.get(
                        f"{weather_forecast_details_url}{station['County']}"
                    ).text
                )["records"]["location"][0]["weatherElement"]

                # 預報時間
                start_time = ":".join(
                    weather_forecast_details_data[0]["time"][0]["startTime"]
                    .split(" ")[1]
                    .split(":")[:2]
                )
                end_time = ":".join(
                    weather_forecast_details_data[0]["time"][0]["endTime"]
                    .split(" ")[1]
                    .split(":")[:2]
                )

                Wx = weather_forecast_details_data[0]["time"][0]["parameter"][
                    "parameterName"
                ]  # 天氣現象
                PoP = weather_forecast_details_data[1]["time"][0]["parameter"][
                    "parameterName"
                ]  # 降雨機率
                MinT = weather_forecast_details_data[2]["time"][0]["parameter"][
                    "parameterName"
                ]  # 最低溫度
                CI = weather_forecast_details_data[3]["time"][0]["parameter"][
                    "parameterName"
                ]  # 舒適度
                MaxT = weather_forecast_details_data[4]["time"][0]["parameter"][
                    "parameterName"
                ]  # 最高溫度

                message_forecast = f"""【詳細預報數據】
預報時間：{start_time} ~ {end_time}
天氣現象：{Wx}
降雨機率：{PoP}%
舒適度：{CI}
溫度：{MinT}°C ~ {MaxT}°C"""

                find_forecast = True

            if (
                f"{station['County']}{station['Town']}" in address.replace("台", "臺")
                and find_current is False
            ):
                ## 現在天氣數據 ##
                for i in range(0, len(weather_now_urls)):
                    weather_current_data = json.loads(
                        requests.get(
                            f"{weather_now_urls[i]}{station['StationId']}"
                        ).text
                    )["records"]["Station"]

                    if weather_current_data != []:  # 如果目前地區有觀測站
                        weather_current_data = weather_current_data[0]["WeatherElement"]

                        weather = weather_current_data["Weather"]  # 天氣現象
                        if i == 0:
                            visibility_description = weather_current_data[
                                "VisibilityDescription"
                            ]  # 能見度
                        precipitation = weather_current_data["Now"][
                            "Precipitation"
                        ]  # 當日降水量
                        wind_direction = weather_current_data["WindDirection"]  # 風向
                        wind_speed = weather_current_data["WindSpeed"]  # 風速
                        air_temperature = weather_current_data["AirTemperature"]  # 氣溫
                        relative_humidity = weather_current_data[
                            "RelativeHumidity"
                        ]  # 相對濕度
                        air_pressure = weather_current_data["AirPressure"]  # 大氣壓力
                        if i == 0:
                            uv_index = weather_current_data["UVIndex"]  # 紫外線指數

                        message_current = f"""【現在天氣數據】
天氣現象：{weather}
當日降水量：{precipitation}mm
風向：{wind_direction}
風速：{wind_speed}m/s
氣溫：{air_temperature}°C
相對濕度：{relative_humidity}%
大氣壓力：{air_pressure}hPa"""

                        if i == 0:
                            message_current += f"""
能見度：{visibility_description}km
紫外線指數：{uv_index}"""

                        find_current = True
                        break

            if find_forecast is True and find_current is True:
                break

        if message_current == "":
            message_current = "【現在天氣數據】\n⚠️目前地區無觀測資料"

        return [{"type": "text", "text": overview} for overview in overviews] + [
            {"type": "text", "text": message_forecast},
            {"type": "text", "text": message_current},
        ]

    #### 雷達回波 ####
    elif data["events"][0]["message"]["text"] == "雷達回波":
        return [
            {
                "type": "image",
                "originalContentUrl": "https://cwaopendata.s3.ap-northeast-1.amazonaws.com/Observation/O-A0058-001.png",
                "previewImageUrl": "https://cwaopendata.s3.ap-northeast-1.amazonaws.com/Observation/O-A0058-001.png",
            }
        ]

    #### 地震資訊 ####
    elif data["events"][0]["message"]["text"] == "地震資訊":
        earthquake_data = requests.get(earthquake_url).json()["records"]["Earthquake"][
            0
        ]

        ### 處理訊息 ###
        # 地震編號
        number = earthquake_data["EarthquakeNo"]

        ## EarthquakeInfo ##
        earthquake_info = earthquake_data["EarthquakeInfo"]

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

        message = f"""地震編號：第{number}號
發震時間：{int(date[0]) - 1911}年{date[1]}月{date[2]}日{time[0]}時{time[1]}分{time[2]}秒
震央位置：北緯{latitude}°   東經{longitude}°
震源深度：{focal_depth}公里
芮氏規模：{magnitude}
相對位置：{location}
"""

        ## ShakingArea ##
        shaking_area = sorted(
            earthquake_data["Intensity"]["ShakingArea"],
            key=lambda x: x["AreaIntensity"],
            reverse=True,
        )

        message += "最大震度級\n"
        for area in shaking_area:
            if "最大震度" not in area["AreaDesc"]:
                message += f"● {area['AreaDesc']} 最大震度 {area['AreaIntensity']}"

                pre_intensity = 0
                first = True
                for eq_station in area["EqStation"]:
                    if pre_intensity != eq_station["SeismicIntensity"]:
                        message += f"\n   {eq_station['SeismicIntensity']}："

                        pre_intensity = eq_station["SeismicIntensity"]
                        first = True

                    if first is False:
                        message += "、"
                    message += f"{eq_station['StationName']}"

                    first = False

                message += "\n"

        return [
            {"type": "text", "text": message},
            {
                "type": "image",
                "originalContentUrl": earthquake_data["ReportImageURI"],
                "previewImageUrl": earthquake_data["ReportImageURI"],
            },
        ]
