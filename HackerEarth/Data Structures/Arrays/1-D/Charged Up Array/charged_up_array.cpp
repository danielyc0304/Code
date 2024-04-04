/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/charged-up-array-f35a5e23/
Title: Charged Up Array
Time: 2024-04-04 11:47:43 Add
*/
#include <cmath>
#include <iostream>
using namespace std;

const int kMod = 1000000007;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        long int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%ld", &A[j]);
        }

        if (N >= 60) {
            printf("0\n");
        } else {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                if (A[j] >= pow(2, N - 1)) {
                    sum = (sum + A[j]) % kMod;
                }
            }

            printf("%d\n", sum);
        }
    }

    return 0;
}
