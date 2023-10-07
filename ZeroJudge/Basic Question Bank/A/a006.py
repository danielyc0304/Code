"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a006
Title: 一元二次方程式
Time: 2023-10-07 11:44:23 Add
"""

a, b, c = map(int, input().split())

s = b**2 - 4 * a * c

if s < 0:
    print("No real root")
else:
    x1 = (-b + int(s**0.5)) // (2 * a)
    x2 = (-b - int(s**0.5)) // (2 * a)

    if x1 == x2:
        print(f"Two same roots x={x1}")
    else:
        print(f"Two different roots x1={x1} , x2={x2}")
