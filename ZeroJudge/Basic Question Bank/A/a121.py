"""
Problem: https://zerojudge.tw/ShowProblem?problemid=a121
Title: 質數又來囉
Time: 2023-10-26 13:13:49 Add
"""

MAX = int(100000000**0.5)

prime = [2]
is_prime = [
    False if i in [0, 1] + list(range(4, MAX + 1, 2)) else True for i in range(MAX + 1)
]

for i in range(3, MAX + 1, 2):
    if is_prime[i] is True:
        for j in prime:
            if i % j == 0:
                is_prime[i] = False

                break

        if is_prime[i] is True:
            prime.append(i)

            for j in range(i * i, MAX + 1, 2 * i):
                is_prime[j] = False


def is_Prime(num):
    if num <= MAX:
        return is_prime[num]

    for i in prime:  # num > MAX
        if num % i == 0:
            return False
    return True


while True:
    try:
        a, b = map(int, input().split())
    except EOFError:
        break

    c = 0

    if a <= 2 <= b:
        c += 1
        a = 3
    for i in range(a + (1 - a % 2), b + (b % 2), 2):  # a改為奇數，b改為偶數
        c += is_Prime(i)

    print(c)
