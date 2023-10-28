"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a225
Title: 明明愛排列
Time: 2023-10-28 20:35:08 Add
"""

while True:
    try:
        ign = input()
    except EOFError:
        break

    num = [f"0{i}" for i in input().split()]  # 確保每個數字都是兩位數以上，s[:-1]才不會出錯

    num.sort(key=lambda x: int(x[:-1]), reverse=True)  # 先排序十位以上，由大到小
    num.sort(key=lambda x: int(x[-1]))  # 再排序個位，由小到大

    print(*[int(i) for i in num])
