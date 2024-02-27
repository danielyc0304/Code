/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-and-xor-or-6a05bbd4/
Title: Minimum AND xor OR
Time: 2024-02-27 16:05:49 Add
*/

#include <algorithm>
#include <climits>
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

        sort(A, A + N);  // TODO 先進行排序就可以得出最終答案，目前不知道為什麼

        int num_min = INT_MAX;
        for (int j = 0; j < N - 1; j++) {
            num_min = min(
                num_min,
                A[j] ^
                    A[j + 1]);  // (A[i] & A[j]) ^ (A[i] | A[j]) = A[i] ^ A[j]
        }

        printf("%d\n", num_min);
    }

    return 0;
}
