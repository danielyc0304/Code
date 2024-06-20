import os
from shutil import copyfile

ROOT = "/Users/daniel/Desktop/Photo"

with open("/Users/daniel/Desktop/Code/Project/Photo Select/photo.txt", "r") as file:
    os.chdir(ROOT)

    # 讀取新資料夾名稱
    new_file = file.readline().strip()
    os.mkdir(new_file)

    # 讀取開始日期
    start_date = file.readline().strip().replace("/", ":")

    months = sorted([path for path in os.listdir() if os.path.isdir(f"{ROOT}/{path}")])
    month = months.index(start_date[:7])

    dates = sorted(
        [
            path
            for path in os.listdir(f"{ROOT}/{months[month]}")
            if os.path.isdir(f"{ROOT}/{months[month]}/{path}")
        ]
    )
    date = dates.index(start_date)

    locations = sorted(
        [
            path
            for path in os.listdir(f"{ROOT}/{months[month]}/{dates[date]}")
            if os.path.isdir(f"{ROOT}/{months[month]}/{dates[date]}/{path}")
        ]
    )
    location = 0

    os.chdir(f"{ROOT}/{months[month]}/{dates[date]}/{locations[location]}")

    # 讀取目標照片
    photos = []
    for line in file.readlines():
        if "-" in line:
            for i in range(int(line.split("-")[0]), int(line.split("-")[1]) + 1):
                photos.append(f"DSC{'0' * (5 - len(str(i)))}{i}.JPG")
        else:
            photos.append(f"DSC{'0' * (5 - len(line.strip()))}{line.strip()}.JPG")
    for photo in photos:
        while os.path.exists(photo) is False:
            location += 1

            # 換日
            date += location // len(locations)
            location %= len(locations)

            # 換月
            month += date // len(dates)
            date %= len(dates)

            # 如果換月了
            if date == 0:
                dates = sorted(
                    [
                        path
                        for path in os.listdir(f"{ROOT}/{months[month]}")
                        if os.path.isdir(f"{ROOT}/{months[month]}/{path}")
                    ]
                )  # 獲取新的日期

            # 如果換日了（如果換月即會換日）
            if location == 0:
                locations = sorted(
                    [
                        path
                        for path in os.listdir(f"{ROOT}/{months[month]}/{dates[date]}")
                        if os.path.isdir(f"{ROOT}/{months[month]}/{dates[date]}/{path}")
                    ]
                )  # 獲取新的地點

            os.chdir(f"{ROOT}/{months[month]}/{dates[date]}/{locations[location]}")

        copyfile(photo, f"{ROOT}/{new_file}/{photo}")
