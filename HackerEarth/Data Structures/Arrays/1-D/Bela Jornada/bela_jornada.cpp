/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/beautiful-journey-1/
Title: Bela Jornada
Time: 2024-04-23 14:40:25 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int A[N + 1];
    A[0] = 0;
    for (int i = 1; i <= N; i++) {
        scanf("%d", &A[i]);

        A[i] += A[i - 1];
    }

    long int num = 0;
    for (int i = 1; i <= N; i++) {
        num = max(num, (long int)A[i] * (A[N] - A[i]));
    }

    printf("%ld\n", num);

    return 0;
}
