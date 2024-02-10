/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/double-inversions-2-881a7d34/
Title: Double inversions
Time: 2024-02-10 18:09:20 Add
*/

#include <iostream>
#include <set>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int n;
        scanf("%d", &n);

        int A[n], R[n];
        for (int j = 0; j < n; j++) {
            scanf("%d", &A[j]);
        }
        for (int j = 0; j < n; j++) {
            scanf("%d", &R[j]);
        }

        int num[n];
        set<int> num_set;
        for (int j = 0; j < n; j++) {
            num[j] = n - A[j] - R[n - j - 1];
            num_set.insert(num[j]);
        }

        if (num_set.size() == n && *num_set.begin() == 1) {
            for (int j = 0; j < n; j++) {
                printf("%d ", num[j]);
            }
            printf("\n");
        } else {
            printf("-1\n");
        }
    }

    return 0;
}
