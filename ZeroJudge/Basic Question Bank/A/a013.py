"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a013
Title: 羅馬數字
Time: 2023-10-07 16:20:00 Add
"""


def Roman_to_int(Roman):
    dic = {"M": 1000, "D": 500, "C": 100, "L": 50, "X": 10, "V": 5, "I": 1}

    s = dic[Roman[0]]
    
    for i in range(1, len(Roman)):
        s += dic[Roman[i]]
        if dic[Roman[i - 1]] < dic[Roman[i]]:
            s -= 2 * dic[Roman[i - 1]]

    return s


def int_to_Roman(num):
    dic = [
        [1000, "M"],
        [900, "CM"],
        [500, "D"],
        [400, "CD"],
        [100, "C"],
        [90, "XC"],
        [50, "L"],
        [40, "XL"],
        [10, "X"],
        [9, "IX"],
        [5, "V"],
        [4, "IV"],
        [1, "I"],
    ]

    Roman = ""

    for i in dic:
        c, num = divmod(num, i[0])
        Roman += c * i[1]

    return Roman


while True:
    Roman = input()

    if Roman == "#":
        break

    num1 = Roman_to_int(Roman.split()[0])
    num2 = Roman_to_int(Roman.split()[1])

    if num1 - num2 == 0:
        print("ZERO")
    else:
        print(int_to_Roman(abs(num1 - num2)))
