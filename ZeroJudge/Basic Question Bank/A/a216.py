"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a216
Title: 數數愛明明
Time: 2023-10-27 08:46:19 Add
"""

f = [1 if i == 1 else 0 for i in range(30001)]
g = [1 if i == 1 else 0 for i in range(30001)]

for i in range(2, 30001):
    f[i] = i + f[i - 1]
    g[i] = f[i] + g[i - 1]

while True:
    try:
        n = int(input())
    except EOFError:
        break

    print(f[n], g[n])
