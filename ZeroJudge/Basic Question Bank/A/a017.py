"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a017
Title: 五則運算
Time: 2023-10-07 22:54:01 Add
"""

while True:
    try:
        print(eval(input().replace("/", "//")))
    except EOFError:
        break
