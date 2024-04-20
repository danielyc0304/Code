/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/thief-and-warehouses-6ebf4e07/
Title: Thief and Warehouses
Time: 2024-04-19 00:05:04 Add
*/

#include <iostream>
#include <stack>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N;
        scanf("%d", &N);

        long int a[N];
        for (int j = 0; j < N; j++) {
            scanf("%ld", &a[j]);
        }

        stack<int> num;
        long int max_num = 0;
        for (int j = 0; j < N;) {  // top往左延伸
            if (num.empty() == true || a[num.top()] <= a[j]) {
                num.push(j++);
            } else {
                int top = num.top();
                num.pop();

                if (num.empty() == true) {
                    max_num = max(max_num, a[top] * j);
                } else {
                    max_num = max(max_num, a[top] * ((j - 1) - num.top()));
                }
            }
        }
        while (num.empty() == false) {  // top往右延伸
            int top = num.top();
            num.pop();

            if (num.empty() == true) {
                max_num = max(max_num, a[top] * N);
            } else {
                max_num = max(max_num, a[top] * ((N - 1) - num.top()));
            }
        }

        printf("%ld\n", max_num);
    }

    return 0;
}
