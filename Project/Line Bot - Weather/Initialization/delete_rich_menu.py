import linebot.v3.messaging as messaging


# Line Bot API
channel_access_token = "Vs4TxhGvoovBwRk6IOWB8sWS3sCiGlg2t36+d11xb8ZY2P0dzGQh/rFuGyWmyV9EEenVM9RzrjdPx8E5FRCVxL1z0USJHyYpdCx9RzZcLt1LwX9yvwfwwhKrLoE4Bwyb7MwY1AzCjXcdBvFhWCvv6wdB04t89/1O/w1cDnyilFU="

configuration = messaging.Configuration(access_token=channel_access_token)


with messaging.ApiClient(configuration) as api_client:
    api_instance = messaging.MessagingApi(api_client)

    for i in api_instance.get_rich_menu_list().richmenus:
        api_instance.delete_rich_menu(i.rich_menu_id)
        print(f"Delete menu: {i.rich_menu_id}")
