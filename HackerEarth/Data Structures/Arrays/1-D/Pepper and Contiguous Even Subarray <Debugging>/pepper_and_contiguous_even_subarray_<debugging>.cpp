/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/pepper-and-contiguous-even-subarray-9f3adf65/
Title: Pepper and Contiguous Even Subarray <Debugging>
Time: 2024-04-18 23:02:11 Add
*/

#include <iostream>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        int A[N];
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);
        }

        int c = 0, max_num = 0;
        for (int j = 0; j < N; j++) {
            if (A[j] % 2 == 0) {
                c++;
            } else {
                max_num = max(max_num, c);
                c = 0;
            }
        }
        max_num = max(max_num, c);

        printf("%d\n", (max_num == 0) ? -1 : max_num);
    }

    return 0;
}
