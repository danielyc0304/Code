/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/in-an-array-9fbe4c12/
Title: In an array
Time: 2024-03-26 15:01:45 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N, K, X, Y;
    scanf("%d %d %d %d", &N, &K, &X, &Y);

    int A[K];
    for (int i = 0; i < K; i++) {
        A[i] = 0;
    }
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        A[num % K]++;
    }

    long int c = 0;
    for (int i = 0; i < K; i++) {
        for (int j = i; j < K; j++) {
            if ((i + j) % K == X && (i * j) % K == Y) {
                if (i == j && A[i] != 1) {
                    c += (long int)A[i] * (A[i] - 1) / 2;
                } else {
                    c += (long int)A[i] * A[j];
                }
            }
        }
    }

    printf("%ld\n", c);

    return 0;
}
