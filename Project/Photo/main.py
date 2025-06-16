import os
import sys
from shutil import copyfile, rmtree

ROOT = "/Volumes/Transcend/Photo"

with open("/Users/daniel/Desktop/Code/Project/Photo/photo.txt", "r") as file:
    os.chdir(ROOT)

    # 讀取新資料夾名稱
    new_file = file.readline().strip()
    if os.path.exists(new_file) is True:
        rmtree(new_file)
    os.mkdir(new_file)

    # 讀取開始日期
    start_date = file.readline().strip().replace("/", ":")

    years = sorted([path for path in os.listdir() if "年" in path])
    year = years.index(f"{start_date[:4]}年")

    months = sorted(
        [path for path in os.listdir(f"{ROOT}/{years[year]}") if "月" in path]
    )
    month = months.index(f"{start_date[5:7]}月")

    dates = sorted(
        [
            path
            for path in os.listdir(f"{ROOT}/{years[year]}/{months[month]}")
            if "日" in path
        ]
    )
    date = dates.index(f"{start_date[8:10]}日")

    locations = sorted(
        [
            path
            for path in os.listdir(
                f"{ROOT}/{years[year]}/{months[month]}/{dates[date]}"
            )
            if os.path.isdir(
                f"{ROOT}/{years[year]}/{months[month]}/{dates[date]}/{path}"
            )
        ],
        key=lambda x: int(x.split(" ")[0][:-1]),
    )
    location = 0

    os.chdir(
        f"{ROOT}/{years[year]}/{months[month]}/{dates[date]}/{locations[location]}"
    )

    # 讀取目標照片
    photos = []
    for include in file.readlines():
        if "-" in include:
            exclude = []

            if "ex" in include:
                include, exclude = include.split("ex")
                exclude = [int(photo) for photo in exclude.split(",")]

            for i in range(int(include.split("-")[0]), int(include.split("-")[1]) + 1):
                if i not in exclude:
                    photos.append(f"DSC{'0' * (5 - len(str(i)))}{i}.JPG")
        else:
            photos.append(f"DSC{'0' * (5 - len(include.strip()))}{include.strip()}.JPG")
    for photo in photos:
        try:
            while os.path.exists(photo) is False:
                location += 1

                # 換日
                date += location // len(locations)
                location %= len(locations)

                # 換月
                month += date // len(dates)
                date %= len(dates)

                year += month // len(months)
                month %= len(months)

                # 如果換年了
                if month == 0:
                    months = sorted(
                        [
                            path
                            for path in os.listdir(f"{ROOT}/{years[year]}")
                            if "月" in path
                        ]
                    )

                # 如果換月了（如果換年即會換月）
                if date == 0:
                    dates = sorted(
                        [
                            path
                            for path in os.listdir(
                                f"{ROOT}/{years[year]}/{months[month]}"
                            )
                            if "日" in path
                        ]
                    )  # 獲取新的日期

                # 如果換日了（如果換月即會換日）
                if location == 0:
                    locations = sorted(
                        [
                            path
                            for path in os.listdir(
                                f"{ROOT}/{years[year]}/{months[month]}/{dates[date]}"
                            )
                            if os.path.isdir(
                                f"{ROOT}/{years[year]}/{months[month]}/{dates[date]}/{path}"
                            )
                        ],
                        key=lambda x: int(x.split(" ")[0][:-1]),
                    )  # 獲取新的地點

                os.chdir(
                    f"{ROOT}/{years[year]}/{months[month]}/{dates[date]}/{locations[location]}"
                )

            copyfile(photo, f"{ROOT}/{new_file}/{photo}")
            print(f"Copy {photo}")

        except IndexError:
            print(f"Can't find {photo}")
            sys.exit(1)
