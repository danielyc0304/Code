"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a149
Title: 乘乘樂
Time: 2023-10-26 15:20:18 Add
"""

for _ in range(int(input())):
    n = input()

    s = 1

    for i in n:
        s *= int(i)

    print(s)
