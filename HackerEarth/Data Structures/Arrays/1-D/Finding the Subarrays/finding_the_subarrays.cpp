/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/counting-the-subarrays-4187713a/
Title: Finding the Subarrays
Time: 2024-04-03 15:38:40 Add
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int A[N + 1];
    A[0] = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        scanf("%d", &num);

        A[i] = A[i - 1] + num;
    }

    vector<pair<int, int>> num;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            if (i == 1 && j == N) {
                num.push_back(make_pair(i, j));
            } else {
                double avg = (double)(A[j] - A[i - 1]) / (j - i + 1),
                       remain_avg =
                           (double)((A[N] - A[j]) + (A[i - 1] - A[0])) /
                           (N - (j - i + 1));

                if (avg > remain_avg) {
                    num.push_back(make_pair(i, j));
                }
            }
        }
    }

    printf("%zu\n", num.size());
    for (int i = 0; i < num.size(); i++) {
        printf("%d %d\n", num[i].first, num[i].second);
    }

    return 0;
}
