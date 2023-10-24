"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a040
Title: 阿姆斯壯數
Time: 2023-10-08 14:51:17 Add
                          Docs: 新增TODO
      2023-10-24 14:56:03 Fix: 修正迴圈會捨棄輸入的最後一個數字的問題
"""

n, m = map(int, input().split())

find = False

for i in range(n, m + 1):
    if sum(map(lambda x: int(x) ** len(str(i)), str(i))) == i:
        print(i, end=" ")

        find = True

if find is False:
    print("none")

"""
TODO 輸出後面會跟著未知的'%'，但是不影響AC
input: 100 999
output: 153 370 371 407 %
"""
