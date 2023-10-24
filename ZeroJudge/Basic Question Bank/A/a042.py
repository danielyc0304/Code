"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a042
Title: 平面圓形切割
Time: 2023-10-24 18:14:13 Add
"""

while True:
    try:
        n = int(input())
    except EOFError:
        break

    print(n**2 - n + 2)
