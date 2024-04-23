/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/testing-strings-d1f28949/
Title: Testing Strings
Time: 2024-04-22 14:13:53 Add
*/

#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int kMod = 1000003;

int main() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    vector<int> not_include_num[M + 1], include_num[M + 1];
    for (int i = 0; i < N; i++) {  // 不同筆輸入之間，同數字的區間可能會重疊
        int L, R, Z;
        scanf("%d %d %d", &L, &R, &Z);

        not_include_num[L].push_back(Z);
        include_num[R].push_back(Z);
    }

    map<int, int> not_include_letter_num;
    int possible = 1;
    for (int i = 1; i <= M; i++) {
        for (int j = 0; j < not_include_num[i].size(); j++) {
            not_include_letter_num[not_include_num[i][j]]++;
        }

        possible = ((long int)possible * (K - not_include_letter_num.size())) % kMod;

        for (int j = 0; j < include_num[i].size(); j++) {
            not_include_letter_num[include_num[i][j]]--;
            if (not_include_letter_num[include_num[i][j]] <= 0) {
                not_include_letter_num.erase(include_num[i][j]);
            }
        }
    }

    printf("%d\n", possible);

    return 0;
}
