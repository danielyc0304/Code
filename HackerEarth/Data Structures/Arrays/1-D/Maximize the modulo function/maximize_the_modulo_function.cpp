/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-modulo-2-0cb15ded/
Title: Maximize the modulo function
Time: 2024-02-22 14:54:59 Add
*/

#include <iostream>
using namespace std;

int power(int a, int b, int K) {
    int ans = 1, num = a;
    while (b > 0) {
        if (b % 2 == 1) {
            ans = ((long int)ans * num) % K;
        }
        num = ((long int)num * num) % K;
        b /= 2;
    }

    return ans;
}
int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int M, K;
        scanf("%d %d\n", &M, &K);

        char S[M];
        int sum = 0;
        for (int j = 0; j < M; j++) {
            scanf("%c", &S[j]);

            sum =
                (sum + (long int)(S[j] - 48) * power(10, M - j - 1, K) % K) % K;
        }

        int max_num = sum;
        int previous = 0;
        for (int j = 0; j < M; j++) {
            sum = (sum - (long int)(S[j] - 48) * power(10, M - j - 1, K) % K +
                   K) %
                  K;  // 要加上K避免減法運算出現負數

            max_num = max(max_num, (sum + previous) % K);

            previous =
                (previous + (long int)(S[j] - 48) * power(10, M - j - 2, K) % K) % K;
        }

        printf("%d\n", max_num);
    }

    return 0;
}
