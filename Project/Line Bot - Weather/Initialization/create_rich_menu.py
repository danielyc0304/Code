import linebot.v3.messaging as messaging
import linebot.v3.messaging.models as models

import requests


# Line Bot API
channel_access_token = "Vs4TxhGvoovBwRk6IOWB8sWS3sCiGlg2t36+d11xb8ZY2P0dzGQh/rFuGyWmyV9EEenVM9RzrjdPx8E5FRCVxL1z0USJHyYpdCx9RzZcLt1LwX9yvwfwwhKrLoE4Bwyb7MwY1AzCjXcdBvFhWCvv6wdB04t89/1O/w1cDnyilFU="

configuration = messaging.Configuration(access_token=channel_access_token)


with messaging.ApiClient(configuration) as api_client:
    api_instance = messaging.MessagingApi(api_client)

    # 設定選單
    rich_menu_request = messaging.RichMenuRequest(
        size=models.RichMenuSize(
            width=2500, height=640
        ),  # width要在800~2500之間，height至少要250，ratio至少要1.45
        selected=True,
        name="選單",
        chatBarText="選單",
        areas=[
            models.RichMenuArea(
                bounds=models.RichMenuBounds(x=0, y=0, width=1250, height=640),
                action=models.URIAction(
                    label="location",
                    uri="https://line.me/R/nv/location/",
                    altUri=None,
                ),
            ),
            models.RichMenuArea(
                bounds=models.RichMenuBounds(x=1251, y=0, width=625, height=640),
                action=models.MessageAction(label="radar", text="雷達回波"),
            ),
            models.RichMenuArea(
                bounds=models.RichMenuBounds(x=1879, y=0, width=625, height=640),
                action=models.MessageAction(label="earthquake", text="地震資訊"),
            ),
        ],
    )
    api_response = api_instance.create_rich_menu(rich_menu_request)

    # 設定選單背景
    # 不要使用messaging.MessagingApiBlob.set_rich_menu_image，懷疑這個方法寫錯
    headers = {
        "Authorization": f"Bearer {channel_access_token}",
        "Content-Type": "image/jpeg",
    }
    request = requests.request(
        "POST",
        f"https://api-data.line.me/v2/bot/richmenu/{api_response.rich_menu_id}/content",
        headers=headers,
        data=open("./menu.jpg", "rb"),
    )

    # 設定為預設選單
    api_instance.set_default_rich_menu(api_response.rich_menu_id)
