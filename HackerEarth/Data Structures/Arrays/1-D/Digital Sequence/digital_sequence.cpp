/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/digitial-sequence-ee0ea080/
Title: Digital Sequence
Time: 2024-04-18 15:36:00 Add
*/

// 題意：找出0-9哪個數字出現在最多組數字裡面，並輸出出現的組數

#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    int digits[10] = {0};  // 每個數字總共在幾組數字裡面出現
                           // e.g. digits[1] = 3，代表1出現在3組數字裡面
    for (int i = 0; i < N; i++) {
        int num;
        scanf("%d", &num);

        int c[10] = {0};
        for (; num > 0; num /= 10) {
            c[num % 10]++;

            if (c[num % 10] == 1) {
                digits[num % 10]++;
            }
        }
    }

    int max_num = 0;
    for (int i = 0; i < 10; i++) {
        max_num = max(max_num, digits[i]);
    }

    printf("%d\n", max_num);

    return 0;
}
