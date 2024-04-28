/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/fredo-and-large-numbers/
Title: Fredo and Large Numbers
Time: 2024-04-27 14:46:02 Add
*/

#include <algorithm>
#include <iostream>
using namespace std;

long int A[1000000], sorted_A[1000000];
long int mapping_value[1000001];
int frequency[1000001] = {0}, exactly[1000001] = {0}, at_least[1000001] = {0};

int main() {
    int N;
    scanf("%d", &N);

    for (int i = 0; i < N; i++) {
        scanf("%ld", &A[i]);
        sorted_A[i] = A[i];
    }

    sort(sorted_A, sorted_A + N);

    int max_frequency = 0;
    for (int i = 0; i < N; i++) {
        // 壓縮大小，用原數字紀錄頻率會需要開10^18大小的陣列，所以使用位置映射的方式把大小縮小到10^6
        long int tmp = A[i];
        A[i] =
            lower_bound(sorted_A, sorted_A + N, A[i]) - sorted_A +
            1;  // 將原數字陣列改成排序過後的位置資訊，但映射過後的還是原本出現的順序
        mapping_value[A[i]] = tmp;  // 原值存在映射陣列

        frequency[A[i]]++;
        max_frequency = max(max_frequency, frequency[A[i]]);
    }

    for (int i = 0; i < N; i++) {
        for (int j = frequency[A[i]]; j > 0 && at_least[j] == 0;
             j--) {  // at_least
            at_least[j] = A[i];
        }

        if (exactly[frequency[A[i]]] == 0) {  // exactly
            exactly[frequency[A[i]]] = A[i];
        }
    }

    int Q;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        int type;
        long int f;
        scanf("%d %ld", &type, &f);

        if (f > max_frequency) {
            printf("0\n");
        } else {
            if (type == 0) {
                printf("%ld\n", mapping_value[at_least[f]]);
            } else {
                printf("%ld\n", mapping_value[exactly[f]]);
            }
        }
    }

    return 0;
}
