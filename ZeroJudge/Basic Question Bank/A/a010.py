"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a010
Title: 因數分解
Time: 2023-10-07 13:26:03 Add
"""

num = int(input())

find = False

for i in [2, 3] + [k for j in range(6, int(num**0.5) + 1, 6) for k in [j - 1, j + 1]]:
    c = 0
    while num % i == 0:
        num //= i
        c += 1
    if c > 0:
        print(f'{" * " if find is True else ""}{i}{f"^{c}" if c > 1 else ""}', end="")

        find = True

    if num == 1:
        break

if num != 1:
    print(f'{" * " if find is True else ""}{num}')
