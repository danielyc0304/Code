"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a022
Title: 迴文
Time: 2023-10-08 11:18:25 Add
      2023-10-24 20:43:00 Refactor
"""

str = input()

print("yes" if str == str[::-1] else "no")
