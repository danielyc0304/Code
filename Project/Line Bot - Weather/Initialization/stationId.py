import requests
import json


## 中央氣象署 API ##
cwa_token = "CWA-54E742AA-901E-45B0-84E1-42EF6CE8FFA8"
# 自動雨量站-雨量觀測資料 API
rainfall_url = f"https://opendata.cwa.gov.tw/api/v1/rest/datastore/O-A0002-001?Authorization={cwa_token}&RainfallElement=Now&GeoInfo=CountyName,TownName"


# 使用自動雨量站-雨量觀測資料，裡面有最多鄉鎮
data = requests.get(rainfall_url).json()

location = []
for station in data["records"]["Station"]:
    location.append(
        {
            "StationName": station["StationName"],
            "StationId": station["StationId"],
            "County": station["GeoInfo"]["CountyName"],
            "Town": station["GeoInfo"]["TownName"],
        }
    )

json.dump(
    location,
    open("/Users/daniel/Desktop/Code/Project/Line Bot/stationId.json", "x"),
    ensure_ascii=False,
)
