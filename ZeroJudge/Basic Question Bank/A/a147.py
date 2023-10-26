"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a147
Title: Print it all
Time: 2023-10-26 14:53:13 Add
"""

while True:
    n = int(input())

    if n == 0:
        break

    print(*[i for i in range(1, n) if i % 7 != 0])
