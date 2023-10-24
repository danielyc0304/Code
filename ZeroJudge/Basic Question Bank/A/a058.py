"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a058
Title: MOD3
Time: 2023-10-24 20:18:58 Add
"""

c = [0 for _ in range(3)]

for _ in range(int(input())):
    c[int(input()) % 3] += 1

print(*c)
