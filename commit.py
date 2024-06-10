import os
import sys

ROOT = f"{os.getcwd()}/ZeroJudge/Basic Question Bank"

action = input("Active (e.g. c-): ")

# commit
if action[0] == "c":
    file = input("Commit file (e.g. a001): ")
    message = input('Commit message (e.g. add): ')

    os.chdir(f"{ROOT}/{file[0].upper()}")
    if os.system(f"git add {file}.py") != 0:
        sys.exit()
    if os.system(f'git commit -m "{message.capitalize()} ZeroJudge {file}.py"') != 0:
        sys.exit()
    if os.system("git push") != 0:
        sys.exit()

# create
if action[1] == "c":
    file = input("Create file (e.g. a001): ")

    if os.path.isdir(f"{ROOT}/{file[0].upper()}") is False:
        os.mkdir(f"{ROOT}/{file[0].upper()}")
    os.chdir(f"{ROOT}/{file[0].upper()}")
    open(f"{file}.py", "x")
