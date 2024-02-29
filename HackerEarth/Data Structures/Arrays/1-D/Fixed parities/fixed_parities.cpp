/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/fixed-parity-440254c0/
Title: Fixed parities
Time: 2024-02-29 15:43:54 Add
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int a[n], b[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    int q;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
        int r1, c1, r2, c2;
        scanf("%d %d", &r1, &c1);
        scanf("%d %d", &r2, &c2);

        int num1 = a[r1 - 1] + b[c1 - 1];
        int num2 = a[r2 - 1] + b[c2 - 1];

        if (num1 % 2 == num2 % 2) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }

    return 0;
}
