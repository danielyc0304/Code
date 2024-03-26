/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/pairs-having-similar-element-eed098aa/
Title: Pairs Having Similar Elements
Time: 2024-03-26 09:26:55 Add
*/

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    sort(A, A + N);

    long int c1 = 0, c2 = 0, sum = 0;
    for (int i = 0; i < N - 1; i++) {
        if (A[i] + 1 == A[i + 1]) {
            c1++;
        } else if (A[i] == A[i + 1]) {
            c1++, c2++;
        } else {
            if (c1 != c2) {
                sum += c1 * (c1 + 1) / 2;
            }

            c1 = 0, c2 = 0;
        }
    }
    if (c1 != c2) {
        sum += c1 * (c1 + 1) / 2;
    }

    printf("%ld\n", sum);

    return 0;
}
