/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/minor-4-41918cb8/
Title: Non-empty subsets
Time: 2024-02-11 00:54:38 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int min_num = INT32_MAX;
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);

            min_num = min(min_num, num);
        }

        printf("%d\n", min_num);
    }

    return 0;
}
