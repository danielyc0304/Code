"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a065
Title: 提款卡密碼
Time: 2023-10-24 20:41:00 Add
"""

password = input()

print(
    "".join(
        [
            str(abs(ord(password[i]) - ord(password[i - 1])))
            for i in range(1, len(password))
        ]
    )
)
