/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minimum-operations-2-8000e855/
Title: Minimum operations
Time: 2024-02-22 13:51:39 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int pre = 0, c = 0;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        if (pre != num) {
            c++;
            pre = num;
        }
    }

    printf("%d\n", c);

    return 0;
}
