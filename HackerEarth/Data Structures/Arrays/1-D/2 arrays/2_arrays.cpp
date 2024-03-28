/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/2-arrays-90c9019c/
Title: 2 arrays
Time: 2024-03-28 13:53:33 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    int cA = 0, sumA = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);

        if (A[i] == -1) {
            cA++;
        } else {
            sumA += A[i];
        }
    }

    int B[N];
    int cB = 0, sumB = 0;
    for (int i = 0; i < N; i++) {
        scanf("%d", &B[i]);

        if (B[i] == -1) {
            cB++;
        } else {
            sumB += B[i];
        }
    }

    if (cA == 1 && cB == 0) {
        if (sumA <= sumB) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    } else if (cA == 0 && cB == 1) {
        if (sumA >= sumB) {
            printf("1\n");
        } else {
            printf("0\n");
        }
    } else if (cA == 2 && cB == 0) {
        if (sumA <= sumB) {
            printf("%d\n", sumB - sumA + 1);
        } else {
            printf("0\n");
        }
    } else if (cA == 0 && cB == 2) {
        if (sumA >= sumB) {
            printf("%d\n", sumA - sumB + 1);
        } else {
            printf("0\n");
        }
    } else {
        printf("Infinite\n");
    }

    return 0;
}
