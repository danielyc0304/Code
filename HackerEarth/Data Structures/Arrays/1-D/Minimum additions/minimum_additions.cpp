/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-additions-0142ac80/
Title: Minimum additions
Time: 2024-02-20 11:02:24 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);

        long long int sum = 0;
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);

            sum += num;
        }

        // 題目所問的不是數字的總和，而是數字的個數，且新增的數字可以是0
        // floor(sum / (N + j)) <= K, K <= sum / (N + j) < K + 1,
        // sum / (K + 1) < N + j, sum / (K + 1) - N < j
        printf("%ld\n", max(sum / (K + 1) - N + 1, (long long int)0));
    }

    return 0;
}
