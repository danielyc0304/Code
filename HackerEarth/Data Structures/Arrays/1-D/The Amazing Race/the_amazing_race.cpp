/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/the-amazing-race-1/
Title: The Amazing Race
Time: 2024-04-29 00:33:47 Add
*/

#include <iostream>
#include <stack>
using namespace std;

// TODO
// 寫得跟解答完全一樣，只是沒加MOD，但是題目也沒有說要加，不知道是不是只有部分AC的原因
int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int H[n + 1];
        for (int j = 1; j <= n; j++) {
            scanf("%d", &H[j]);
        }

        int front[n + 1];  // front[i] -> 第i台車可以看到前面幾台車
        stack<int> index;
        front[1] = 0;
        index.push(1);
        for (int j = 2; j <= n; j++) {
            while (index.empty() == false && H[j] > H[index.top()]) {
                index.pop();
            }

            if (index.empty() == false) {
                front[j] = j - index.top();
            } else {
                front[j] = j - 1;
            }

            index.push(j);
        }

        int back[n + 1];  // back[i] -> 第i台車可以看到後面幾台車
        index = stack<int>();
        back[n] = 0;
        index.push(n);
        for (int j = n - 1; j > 0; j--) {
            while (index.empty() == false && H[j] > H[index.top()]) {
                index.pop();
            }

            if (index.empty() == false) {
                back[j] = index.top() - j;
            } else {
                back[j] = n - j;
            }

            index.push(j);
        }

        long int max_num = 0;
        int index_of_max_num = 0;
        for (int j = 1; j <= n; j++) {
            if ((long int)(front[j] + back[j]) * j > max_num) {
                max_num = (long int)(front[j] + back[j]) * j;
                index_of_max_num = j;
            }
        }

        printf("%d\n", (index_of_max_num != 0) ? index_of_max_num : 1);
    }

    return 0;
}
