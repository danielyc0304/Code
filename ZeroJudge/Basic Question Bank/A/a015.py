"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a015
Title: 矩陣的翻轉
Time: 2023-10-07 17:00:17 Add
"""

while True:
    try:
        r, c = map(int, input().split())
    except EOFError:
        break

    A = [input().split() for _ in range(r)]

    [print(*[A[i][j] for i in range(r)]) for j in range(c)]
