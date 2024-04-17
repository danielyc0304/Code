/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/3/?sort_by=partially%20solved&p_level=
Title: Permute the Array
Time: 2024-04-17 12:01:00 Add
*/

#include <iostream>
#include <map>
using namespace std;

int main() {
    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int N, K;
        scanf("%d %d", &N, &K);

        map<int, int> frequency;
        for (int j = 0; j < N; j++) {
            int num;
            scanf("%d", &num);

            frequency[num]++;
        }

        int times = N / K;
        bool ans = true;
        for (map<int, int>::iterator it = frequency.begin();
             it != frequency.end(); it++) {
            if (it->second % times != 0) {
                ans = false;

                break;
            }
        }

        printf("%s\n", (ans == true) ? "YES" : "NO");
    }

    return 0;
}
