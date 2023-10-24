"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a054
Title: 電話客服中心
Time: 2023-10-24 20:12:02 Add
"""

dic = ["BNZ", "AMW", "KLY", "JVX", "HU", "GT", "FS", "ER", "DOQ", "CIP"]

ID = input()

print(
    dic[
        (
            10
            - sum([(8 - i) * int(ID[i]) for i in range(len(ID) - 1)]) % 10
            - int(ID[-1])
        )
        % 10
    ]
)
