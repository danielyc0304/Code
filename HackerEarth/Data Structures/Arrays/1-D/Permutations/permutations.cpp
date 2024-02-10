/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/nevedle-and-permutations-c6acb85e/
Title: Permutations
Time: 2024-02-10 13:58:09 Add
*/

#include <iostream>
using namespace std;

int main() {
    int n, q;
    scanf("%d %d", &n, &q);

    int num[n + 2];
    int max_left[n + 2];
    num[0] = num[n + 1] = 0;
    max_left[0] = max_left[n + 1] = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &num[i]);

        max_left[i] = max(max_left[i - 1], num[i - 1]);
    }
    int max_right[n + 2];
    max_right[0] = max_right[n + 1] = 0;
    for (int i = n; i > 0; i--) {
        max_right[i] = max(max_right[i + 1], num[i + 1]);
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);

        printf("%d\n", max(max_left[l], max_right[r]));
    }

    return 0;
}
