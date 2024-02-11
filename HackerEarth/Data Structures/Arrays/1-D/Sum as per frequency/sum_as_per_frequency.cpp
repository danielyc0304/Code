/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/sum-as-per-frequency-88b00c1f/
Title: Sum as per frequency
Time: 2024-02-11 01:12:11 Add
*/

#include <iostream>
#include <map>
using namespace std;

long int prefix_sum[1000001] = {0};

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    int frequency[1000001] = {0};
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);

        frequency[A[i]]++;
    }

    for (int i = 0; i < N; i++) {
        prefix_sum[frequency[A[i]]] += A[i];
    }
    for (int i = 2; i <= 1000000; i++) {
        prefix_sum[i] += prefix_sum[i - 1];
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%ld\n", prefix_sum[r] - prefix_sum[l - 1]);
    }

    return 0;
}
