/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-length-4-945227e2/
Title: Minimum Length
Time: 2024-02-06 21:29:05 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int A[N], B[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }
        for (int j = 0; j < N; j++) {
            scanf("%d", &B[j]);
        }

        int l = 0, r = N - 1;
        for (; l < N; l++) {
            if (A[l] != B[l]) {
                break;
            }
        }
        for (; r > l; r--) {
            if (A[r] != B[r]) {
                break;
            }
        }

        printf("%d\n", r - l + 1);
    }

    return 0;
}
