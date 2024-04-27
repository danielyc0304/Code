/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/long-atm-queue-3/
Title: Long ATM Queue
Time: 2024-04-27 14:31:43 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int pre = 0;
    int c = 1;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        if (pre > num) {
            c++;
        }

        pre = num;
    }

    printf("%d\n", c);

    return 0;
}
