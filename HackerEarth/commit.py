import os
import sys

ROOT = f"{os.getcwd()}/Data Structures/Arrays/1-D"

active = input("Active (e.g. c-): ")

# commit
if active[0] == "c":
    file = input("Commit file (e.g. Minimum Length): ")
    message = input("Commit message (e.g. add): ")

    os.chdir(f"{ROOT}/{file}")

    file = file.lower().replace(" ", "_")

    if os.system(f"git add {file}.cpp") != 0:
        sys.exit()
    if os.system(f'git commit -m "{message.capitalize()} HackerEarth {file}.cpp"') != 0:
        sys.exit()
    if os.system("git push") != 0:
        sys.exit()

# create
if active[1] == "c":
    file = input("Create file (e.g. Minimum Length): ")

    os.mkdir(f"{ROOT}/{file}")
    os.chdir(f"{ROOT}/{file}")

    file = file.lower().replace(" ", "_")

    open(f"{file}.cpp", "x")
