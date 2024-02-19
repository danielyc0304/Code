/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/array-queries-again-7948f256/
Title: Array queries
Time: 2024-02-06 22:30:52 Add
*/

#include <iostream>
using namespace std;

const int kMod = 998244353;

int Mod(long long int num) {
    return ((num % kMod) + kMod) %
           kMod;  // TODO 不先加上kMod再取餘數會有問題，目前不知道為什麼
}

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, M;
        scanf("%d %d", &N, &M);

        long long int A[N], B[M];
        long long int sumA = 0, weight_sumA = 0, sumB = 0, weight_sumB = 0;
        for (int j = 0; j < N; j++) {
            scanf("%lld", &A[j]);

            sumA = Mod(sumA + A[j]);
            weight_sumA = Mod(weight_sumA + (j + 1) * A[j]);
        }
        for (int j = 0; j < M; j++) {
            scanf("%lld", &B[j]);

            sumB = Mod(sumB + B[j]);
            weight_sumB = Mod(weight_sumB + (j + 1) * B[j]);
        }

        printf("%d ", Mod(sumA * weight_sumB + sumB * weight_sumA));

        int Q;
        scanf("%d", &Q);

        for (int j = 0; j < Q; j++) {
            int queries[3];
            for (int k = 0; k < 3; k++) {
                scanf("%d", &queries[k]);
            }

            if (queries[0] == 1) {
                sumA = Mod(sumA - A[queries[1] - 1] + B[queries[2] - 1]);
                weight_sumA =
                    Mod(weight_sumA +
                        (queries[1] * (B[queries[2] - 1] - A[queries[1] - 1])));

                sumB = Mod(sumB - B[queries[2] - 1] + A[queries[1] - 1]);
                weight_sumB =
                    Mod(weight_sumB +
                        queries[2] * (A[queries[1] - 1] - B[queries[2] - 1]));

                swap(A[queries[1] - 1], B[queries[2] - 1]);
            } else if (queries[0] == 2) {
                weight_sumA = Mod(weight_sumA +
                                  (queries[2] - queries[1]) *
                                      (A[queries[1] - 1] - A[queries[2] - 1]));

                swap(A[queries[1] - 1], A[queries[2] - 1]);
            } else {
                weight_sumB = Mod(weight_sumB +
                                  (queries[2] - queries[1]) *
                                      (B[queries[1] - 1] - B[queries[2] - 1]));

                swap(B[queries[1] - 1], B[queries[2] - 1]);
            }

            printf("%d ", Mod(sumA * weight_sumB + sumB * weight_sumA));
        }
        printf("\n");
    }

    return 0;
}
