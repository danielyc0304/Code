/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/not-in-range-44d19403/
Title: Not in Range
Time: 2024-04-03 16:48:56 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int c[1000002] = {0};
    for (int i = 0; i < N; i++) {
        int L, R;
        scanf("%d %d", &L, &R);

        c[L]++;
        c[R + 1]--;
    }

    int in_range = 0;
    long int sum = 0;
    for (int i = 1; i <= 1000000; i++) {
        in_range += c[i];

        if (in_range == 0) {
            sum += i;
        }
    }

    printf("%ld\n", sum);

    return 0;
}
