"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a095
Title: 麥哲倫的陰謀
Time: 2023-10-25 00:25:19 Add
"""

while True:
    try:
        N, M = map(int, input().split())
    except EOFError:
        break

    print(M + (N != M))
