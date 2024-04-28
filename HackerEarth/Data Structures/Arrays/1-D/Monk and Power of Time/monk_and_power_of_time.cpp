/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/monk-and-power-of-time/
Title: Monk and Power of Time
Time: 2024-04-28 23:38:21 Add
*/

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    vector<int> calling_order;
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        calling_order.push_back(num);
    }

    int ideal_order[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &ideal_order[i]);
    }

    int time = 0;
    for (int i = 0, j = 0; j < N; j++) {
        while (calling_order[i] !=
               ideal_order[j]) {  // 把還不能做的工作移到最後面
            i = (i + 1) % calling_order.size();
            time++;
        }

        calling_order.erase(calling_order.begin() + i);  // 執行工作
        time++;

        if (calling_order.size() == 0) {
            break;
        }

        i %= calling_order.size();
    }

    printf("%d\n", time);

    return 0;
}
