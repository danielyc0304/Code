/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/micro-and-array-update/
Title: Micro and Array Update
Time: 2024-04-27 05:18:51 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);

        int min_num = 1000000;
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);

            min_num = min(min_num, num);
        }

        printf("%d\n", (K - min_num >= 0) ? K - min_num : 0);
    }

    return 0;
}
