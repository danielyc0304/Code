/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/infinity-array-715a233b/
Title: Infinite arrays
Time: 2024-03-28 14:14:53 Add
*/
#include <iostream>
using namespace std;

const int kMod = 1000000007;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int prefix_sum[N + 1];
        prefix_sum[0] = 0;
        for (int j = 1; j <= N; j++) {
            int num;
            scanf("%d", &num);

            prefix_sum[j] = (prefix_sum[j - 1] + num) % kMod;
        }

        int Q;
        scanf("%d", &Q);

        long int L[Q], R[Q];
        for (int j = 0; j < Q; j++) {
            scanf("%ld", &L[j]);
        }
        for (int j = 0; j < Q; j++) {
            scanf("%ld", &R[j]);
        }

        for (int j = 0; j < Q; j++) {
            long int l = L[j] - 1;
            int sum1 =
                ((l / N % kMod) * prefix_sum[N] % kMod + prefix_sum[l % N]) %
                kMod;

            long int r = R[j];
            int sum2 =
                ((r / N % kMod) * prefix_sum[N] % kMod + prefix_sum[r % N]) %
                kMod;

            printf(
                "%d ",
                (sum2 - sum1 + kMod) %
                    kMod);  // 因為sum1,
                            // sum2先取餘數了，可能造成sum1大於sum2，所以要加上kMod再取餘數
        }
        printf("\n");
    }

    return 0;
}
