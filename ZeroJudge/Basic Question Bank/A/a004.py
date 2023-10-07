"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a004
Title: 文文的求婚
Time: 2023-10-07 11:33:09 Add
"""

while True:
    try:
        year = int(input())
    except EOFError:
        break

    if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0:
        print("閏年")
    else:
        print("平年")
