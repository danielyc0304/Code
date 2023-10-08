"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a022
Title: 迴文
Time: 2023-10-08 11:18:25 Add
"""

str = input()

if str == str[::-1]:
    print("yes")
else:
    print("no")
