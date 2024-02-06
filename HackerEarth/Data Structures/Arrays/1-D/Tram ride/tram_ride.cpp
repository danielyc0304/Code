/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tram-ride-d7ff3a92/
Title: Tram ride
Time: 2024-02-06 21:47:07 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N, start, finish;
    scanf("%d %d %d", &N, &start, &finish);

    long int prefix_sum[N + 1];
    prefix_sum[0] = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);

        prefix_sum[i] = prefix_sum[i - 1] + num;
    }

    long int clockwise =
        abs(prefix_sum[(finish - 1) % N] - prefix_sum[(start - 1) % N]);
    printf("%d\n", min(clockwise, prefix_sum[N] - clockwise));

    return 0;
}
