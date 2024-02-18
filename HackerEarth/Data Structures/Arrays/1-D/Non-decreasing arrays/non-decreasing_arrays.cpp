/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/make-it-non-decreasing-7d3391fd/
Title: Non-decreasing arrays
Time: 2024-02-17 22:01:30 Add
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

        long int B[N];
        B[0] = A[0];
        printf("%d ", B[0]);
        for (int j = 1; j < N; j++) {
            if (A[j] > B[j - 1]) {
                B[j] = A[j];
            } else {
                B[j] =
                    B[j - 1] +
                    (A[j] - B[j - 1] % A[j]) %
                        A[j];  // 加上%A[j]是為了避免餘數為0時，會加上一整個除數
            }

            printf("%ld ", B[j]);
        }
        printf("\n");
    }

    return 0;
}
