import os
import sys

from rich.console import Console
from shutil import copyfile


STORAGE_ROOT = "/Volumes/Transcend/Photo"
CAMERA_ROOT = "/Volumes/Untitled/DCIM"

console = Console()

if os.path.isdir(CAMERA_ROOT) is False:
    sys.exit("Camera not found.")

with console.status("Checking start date...") as status:
    storage_end_year = sorted(
        [folder for folder in os.listdir(STORAGE_ROOT) if "年" in folder],
        key=lambda x: int(x[:-1]),
    )  # 儲存的最後年份
    storage_end_month = sorted(
        [
            folder
            for folder in os.listdir(f"{STORAGE_ROOT}/{storage_end_year[-1]}")
            if "月" in folder
        ],
        key=lambda x: int(x[:2]),
    )  # 儲存的最後月份
    storage_end_day = sorted(
        [
            folder
            for folder in os.listdir(
                f"{STORAGE_ROOT}/{storage_end_year[-1]}/{storage_end_month[-1]}"
            )
            if "日" in folder
        ],
        key=lambda x: int(x[:2]),
    )  # 儲存的最後日期
    storage_end_date = int(
        f"{storage_end_year[-1][-2]}{storage_end_month[-1][:-1]}{storage_end_day[-1][:-1]}"
    )  # 組合成五碼(年月月日日) e.g. 20250210 -> 50210

    camera_folder = sorted(
        [
            folder
            for folder in os.listdir(CAMERA_ROOT)
            if int(folder[3:]) >= storage_end_date
        ],
        key=lambda x: int(x[3:]),
    )  # 存過的照片就不再存，但檢查最後一天

console.print(
    f"Copy starting at 202{camera_folder[0][3]}年{camera_folder[0][4:6]}月{camera_folder[0][6:]}日",
    style="green",
)


with console.status("Copying...") as status:
    for folder in camera_folder:
        os.chdir(f"{CAMERA_ROOT}/{folder}")
        os.makedirs(
            f"{STORAGE_ROOT}/202{folder[3]}年/{folder[4:6]}月/{folder[6:]}日",
            exist_ok=True,
        )

        for photo in [file for file in os.listdir() if file[0] == "D"]:
            status.update(
                f"Current folder: {CAMERA_ROOT}/{folder}\nCopying {photo} ..."
            )
            copyfile(
                photo,
                f"{STORAGE_ROOT}/202{folder[3]}年/{folder[4:6]}月/{folder[6:]}日/{photo}",
            )

        console.print(
            f"Complete copying date 202{folder[3]}年{folder[4:6]}月{folder[6:]}日",
            style="blue",
        )


console.print("Copy completed!", style="green")
