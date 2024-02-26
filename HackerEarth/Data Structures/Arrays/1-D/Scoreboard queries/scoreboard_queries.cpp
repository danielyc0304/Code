/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/tournament-and-ranks-67cd4b7e/
Title: Scoreboard queries
Time: 2024-02-26 11:04:01 Add
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, Q;
        scanf("%d %d", &N, &Q);

        int A[N];
        map<int, int> frequency;
        for (int j = 0; j < N; j++) {
            scanf("%d", &A[j]);

            frequency[A[j]]++;
        }

        for (int j = 0; j < Q; j++) {
            int L, R;
            scanf("%d %d", &L, &R);

            frequency[A[L - 1]]--;
            if (frequency[A[L - 1]] == 0) {
                frequency.erase(A[L - 1]);
            }

            A[L - 1] = R;
            frequency[A[L - 1]]++;

            printf("%zu\n", frequency.size() + 1);
        }
    }
    return 0;
}
