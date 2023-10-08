"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a040
Title: 阿姆斯壯數
Time: 2023-10-08 14:51:17 Add
                          Docs: 新增TODO
"""

find = False

for i in range(*map(int, input().split())):
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
