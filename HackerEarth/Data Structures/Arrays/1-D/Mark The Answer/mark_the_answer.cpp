/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/mark-the-answer-1/
Title: Mark The Answer
Time: 2024-04-28 22:15:48 Add
*/

#include <iostream>
using namespace std;

int main() {
    int N, X;
    scanf("%d %d", &N, &X);

    int A[N];
    for (int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int c = 0;
    bool skip = false;
    for (int i = 0; i < N; i++) {
        if (A[i] <= X) {
            c++;
        } else if (skip == false) {
            skip = true;
        } else {
            break;
        }
    }

    printf("%d\n", c);

    return 0;
}
