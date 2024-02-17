/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/bitwise-and-sum-d8a0d265/
Title: Bitwise AND sum
Time: 2024-02-11 10:28:39 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        long int sum = 0;
        for (int j = 0; j < 25; j++) {  // 看作二進制，並逐位比對
            int l = -1, r = N;          // 找出該位為0的最小子陣列

            for (; l < N - 1 && (A[l + 1] >> j & 1); l++)
                ;
            for (; r > l + 1 && (A[r - 1] >> j & 1); r--)
                ;

            // l+1到r-1之間的子陣列皆必須被2^25-1替代，所以會被計算到的次數就是(l左邊(包含)的數字數+1)*(r右邊(包含Ｆ)的數字數+1)，因為左邊可以選擇替代0到l+1個數字，右邊亦同
            // 需要注意的是此題的替代方式並不是跳著替代，而是線性的
            if (l == N - 1) {  // 整個陣列都為1
                sum += ((long int)N * (N + 1) / 2 - 1) * (1 << j);
            } else if (!(l == -1 &&
                         r == N)) {  // 括號裡面的條件即是整個陣列都為0
                sum += ((long int)(l + 2) * (N - r + 1) - 1) * (1 << j);
            }
        }

        printf("%ld\n", sum);
    }

    return 0;
}
