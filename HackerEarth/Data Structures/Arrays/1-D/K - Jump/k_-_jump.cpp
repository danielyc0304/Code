/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/long-jump-1-7d02705a/
Title: K - Jump
Time: 2024-04-17 16:10:18 Add
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int K;
    scanf("%d", &K);

    int N;
    scanf("%d", &N);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    vector<int> num;
    for (int i = 0; i < N; i++) {  // 看成類似動態規劃的過程
        if (num.empty() == true || A[i] - num.back() >= K) {
            num.push_back(A[i]);
        } else if (A[i] < num.back()) {
            int l = upper_bound(num.begin(), num.end(), A[i]) - num.begin();

            if (l == 0 || A[i] - num[l - 1] >= K) {
                num[l] = A[i];
            }
        }
    }

    printf("%zu\n", num.size());

    return 0;
}
