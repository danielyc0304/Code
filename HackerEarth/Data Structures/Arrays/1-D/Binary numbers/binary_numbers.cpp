/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/the-code-generator-9d3f9afa/
Title: Binary numbers
Time: 2024-02-29 13:53:22 Add
*/

#include <iostream>
using namespace std;

int main() {
    int fibonacci[39];
    fibonacci[0] = 1;
    fibonacci[1] = 2;
    for (int i = 2; i < 39; i++) {
        fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2];
    }

    int T;
    scanf("%d", &T);

    for (int i = 0; i < T; i++) {
        int K;
        scanf("%d", &K);

        string binary = "";
        for (int j = 38; j >= 0; j--) {
            if (K >= fibonacci[j]) {
                binary += "1";
                K -= fibonacci[j];
            } else if (binary != "") {
                binary += "0";
            }
        }

        printf("%s\n", binary.c_str());
    }

    return 0;
}
