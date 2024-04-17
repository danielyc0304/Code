/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/no-sharing-capillary-82ed3fe2/
Title: Takeoff
Time: 2024-04-16 23:40:03 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d\n", &T);

    for (int i = 0; i < T; i++) {
        int N, p, q, r;
        scanf("%d %d %d %d", &N, &p, &q, &r);

        int ans = 0;
        for (int i = min(p, min(q, r)); i <= N; i++) {
            int c = (i % p == 0) + (i % q == 0) + (i % r == 0);
            if (c == 1) {
                ans++;
            }
        }

        printf("%d\n", ans);
    }

    return 0;
}
