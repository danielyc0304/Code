/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/zulu-encounters-a-sequence-problem/
Title: Zulu encounters a Sequence Problem
Time: 2024-04-23 21:49:15 Add
*/

#include <iostream>
using namespace std;

int main() {
    int TEST;
    scanf("%d", &TEST);

    for (int i = 0; i < TEST; i++) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        long int max_num = 0;

        // 先找i到r
        int start = A[0];
        for (int j = 1; j < N; j++) {  // 不遞減(non-decreasing)
            if (A[j - 1] <= A[j]) {
                max_num = max(max_num, (long int)A[j] - start);
            } else {
                start = A[j];
            }
        }
        start = A[0];
        for (int j = 1; j < N; j++) {  // 不遞增(non-increasing)
            if (A[j - 1] >= A[j]) {
                max_num = max(max_num, (long int)start - A[j]);
            } else {
                start = A[j];
            }
        }
        // 再找l到i
        start = A[N - 1];
        for (int j = N - 2; j >= 0; j--) {  // 不遞減(non-decreasing)
            if (A[j] <= A[j + 1]) {
                max_num = max(max_num, (long int)start - A[j]);
            } else {
                start = A[j];
            }
        }
        start = A[N - 1];
        for (int j = N - 2; j >= 0; j--) {  // 不遞增(non-increasing)
            if (A[j] >= A[j + 1]) {
                max_num = max(max_num, (long int)A[j] - start);
            } else {
                start = A[j];
            }
        }

        printf("%ld\n", max_num);
    }

    return 0;
}
