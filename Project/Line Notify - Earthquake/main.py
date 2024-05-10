import requests
import time as t

# Earthquake
earthquake_token = "CWA-54E742AA-901E-45B0-84E1-42EF6CE8FFA8"
earthquake_url = f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/E-A0015-001?Authorization={earthquake_token}&format=JSON"

# Line Notify
line_notify_token = "gA7LycwcrixzzpJKomSZNGS4jTL5W3PjTSrrUILT01O"
line_notify_url = "https://notify-api.line.me/api/notify"

header = {"Authorization": f"Bearer {line_notify_token}"}


pre_number = 0
while True:
    ### Earthquake ###
    data = requests.get(earthquake_url).json()["records"]["Earthquake"][0]

    # 地震編號
    number = data["EarthquakeNo"]
    if pre_number != number:
        ## EarthquakeInfo ##
        earthquake_info = data["EarthquakeInfo"]

        # 發震日期
        day, time = earthquake_info["OriginTime"].split(" ")
        day = day.split("-")
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
發震時間：{int(day[0]) - 1911}年{day[1]}月{day[2]}日{time[0]}時{time[1]}分{time[2]}秒
震央位置：北緯{latitude}°   東經{longitude}°
震源深度：{focal_depth}公里
芮氏規模：{magnitude}
相對位置：{location}
"""
        }

        ## ShakingArea ##
        shaking_area = sorted(
            data["Intensity"]["ShakingArea"],
            key=lambda x: x["AreaIntensity"],
            reverse=True,
        )

        message["message"] += "最大震度級：\n"
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

        ## 加入圖片 ##
        message["imageThumbnail"] = (
            "https://scweb.cwa.gov.tw/webdata/OLDEQ/202405/2024050410315840371_H.png"
        )
        message["imageFullsize"] = (
            "https://scweb.cwa.gov.tw/webdata/OLDEQ/202405/2024050410315840371_H.png"
        )

        ### Line Notify ###
        # 發送訊息
        result = requests.post(line_notify_url, headers=header, data=message)

        print(
            f"{int(day[0]) - 1911}/{day[1]}/{day[2]} {time[0]}:{time[1]}:{time[2]} {number} {result.text}"
        )

        pre_number = number

    t.sleep(60)
