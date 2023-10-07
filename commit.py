import os
import sys

ROOT = f"{os.getcwd()}/ZeroJudge/Basic Question Bank"

# commit
file = input("Commit file: ")

if file != "none":
    os.chdir(f"{ROOT}/{file[0].upper()}")
    if os.system(f"git add {file}.py") != 0:
        sys.exit()
    if os.system(f'git commit -m "Add ZeroJudge {file}.py"') != 0:
        sys.exit()
    if os.system("git push") != 0:
        sys.exit()

# create
file = input("Create file: ")

if file != "none":
    if os.path.isdir(f"{ROOT}/{file[0].upper()}") is False:
        os.mkdir(f"{ROOT}/{file[0].upper()}")
    os.chdir(f"{ROOT}/{file[0].upper()}")
    open(f"{file}.py", "x")
