/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/battlefield-13/
Title: Battlefield (MEDIUM)
Time: 2024-04-26 15:26:45 Add
*/

#include <iostream>
using namespace std;

char s[100000];  // 宣告在main裡面好像會記憶體錯誤

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        scanf("%s", s);

        int k_num_total = 0;
        for (int j = 0; j < n; j++) {
            if (s[j] == 'K') {
                k_num_total++;
            }
        }

        int k_num_in_range = 0;
        for (int j = 0; j < k_num_total; j++) {
            if (s[j] == 'K') {
                k_num_in_range++;
            }
        }

        int max_num = k_num_in_range;
        for (int j = k_num_total; j < 2 * n; j++) {
            k_num_in_range +=
                (s[j % n] == 'K' ? 1 : 0) -
                (s[(j - k_num_total) % n] == 'K'
                     ? 1
                     : 0);  // 加上從右邊加入的K個數，減去從左邊移除的K個數，判斷範圍永遠為k_num_total，找出含有最大K個數的範圍，即可得出最小移動數
            max_num = max(max_num, k_num_in_range);
        }

        printf("%d\n", k_num_total - max_num);
    }

    return 0;
}
