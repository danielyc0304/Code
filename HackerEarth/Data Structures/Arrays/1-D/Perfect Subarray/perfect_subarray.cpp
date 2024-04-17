/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/perfect-subarray-43560f46/discussion/c-solution-passes-al-da0f5196/
Title: Perfect Subarray
Time: 2024-04-17 11:45:20 Add
*/

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int c = 0;
    for (int i = 0; i < N; i++) {
        int sum = 0;
        for (int j = i; j < N; j++) {
            sum += A[j];

            if (floor(sqrt(sum)) == ceil(sqrt(sum))) {
                c++;
            }
        }
    }

    printf("%d\n", c);

    return 0;
}
