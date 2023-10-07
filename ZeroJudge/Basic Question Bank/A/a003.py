"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a003
Title: 兩光法師占卜術
Time: 2023-10-07 11:30:51 Add
"""

M, D = map(int, input().split())

S = (M * 2 + D) % 3

if S == 0:
    print("普通")
elif S == 1:
    print("吉")
else:
    print("大吉")
