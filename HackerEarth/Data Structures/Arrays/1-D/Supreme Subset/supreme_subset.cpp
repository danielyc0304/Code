/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/supreme-subset-bb866a75/
Title: Supreme Subset
Time: 2024-04-22 13:21:11 Add
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int A[n];
    map<int, int> frequency;
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);

        frequency[A[i] % m]++;
    }
    sort(A, A + n);

    int max_frequency = 0;
    for (map<int, int>::iterator it = frequency.begin(); it != frequency.end();
         it++) {
        max_frequency = max(max_frequency, it->second);
    }

    bool find = false;
    vector<int> num;
    for (int i = 0; i < n; i++) {
        if (find == false && frequency[A[i] % m] == max_frequency) {
            num.push_back(A[i]);

            find = true;
        } else if (find == true && A[i] % m == num[0] % m) {
            num.push_back(A[i]);
        }
    }
    sort(num.begin(), num.end());

    printf("%zu\n", num.size());
    for (int i = 0; i < num.size(); i++) {
        printf("%d ", num[i]);
    }
    printf("\n");

    return 0;
}
