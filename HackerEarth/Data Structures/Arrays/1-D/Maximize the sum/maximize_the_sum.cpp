/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/maximize-sum-0423b95e/
Title: Maximize the sum
Time: 2024-02-19 02:00:07 Add
*/

#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
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

        map<int, int>::iterator it = frequency.end();
        it--;
        vector<long int> product;
        while (it->first > 0) {
            product.push_back((long int)it->first * it->second);

            if (it == frequency.begin()) {
                break;
            }

            it--;
        }
        sort(product.begin(), product.end(), greater<long int>());

        long int sum = 0;
        for (int j = 0; j < product.size() && j < K; j++) {
            sum += product[j];
        }

        printf("%ld\n", sum);
    }

    return 0;
}
