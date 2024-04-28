/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/unique-subarrays/
Title: Unique Subarrays
Time: 2024-04-28 20:07:23 Add
*/

#include <iostream>
#include <set>
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

        set<int> num;
        long int sum = 0;
        for (int i = 0, j = 0; i < N; i++) {
            for (; j < N && num.find(A[j]) == num.end(); j++) {
                num.insert(A[j]);
            }

            sum += (long int)(j - i) * (j - i + 1) /
                   2;  // 題意是指一段長度n的連續集合內，有1~n的unique
                       // weight，所以使用公式解每一段unique weight的總和

            num.erase(A[i]);
        }

        printf("%ld\n", sum);
    }

    return 0;
}
