/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/bracket-sequence-1-40eab940/
Title: Bracket sequences
Time: 2024-02-26 13:33:56 Add
*/

#include <cstring>
#include <iostream>
using namespace std;

int main() {
    char s[500000];
    scanf("%s", s);

    int c = 0;
    for (int i = 0; i < strlen(s); i++) {
        if (s[i] == '(') {
            int balance = 0;
            for (int j = i; j < strlen(s); j++) {
                balance += (s[j] == '(' ? 1 : -1);

                if (balance < 0) {
                    break;
                }
            }

            if (balance >= 0) {
                for (int j = 0; j < i; j++) {
                    balance += (s[j] == '(' ? 1 : -1);

                    if (balance < 0) {
                        break;
                    }
                }
            }

            if (balance == 0) {
                c++;
            }
        }
    }

    printf("%d\n", c);

    return 0;
}
