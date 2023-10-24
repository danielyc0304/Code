"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a044
Title: 空間切割
Time: 2023-10-24 18:17:17 Add
"""

while True:
    try:
        n = int(input())
    except EOFError:
        break

    print((n**3 + 5 * n + 6) // 6)
