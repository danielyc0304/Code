"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a104
Title: 排序
Time: 2023-10-25 00:26:45 Add
"""

while True:
    try:
        ign = input()
    except EOFError:
        break

    print(*sorted(map(int, input().split())))
