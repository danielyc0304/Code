"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a003
Title: 兩光法師占卜術
Time: 2023-10-07 11:30:51 Add
      2023-10-25 19:26:28 Refactor
"""

dic = ["普通", "吉", "大吉"]

M, D = map(int, input().split())

print(dic[(M * 2 + D) % 3])
