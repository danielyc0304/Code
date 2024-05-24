#include <iostream>
using namespace std;

int main() {
    int seed;
    scanf("%d", &seed);

    srand(seed);

    int c[3] = {0};
    for (int i = 1; i <= 10; i++) {
        int A = rand() % 6 + 1;
        int B = rand() % 4 * 2;

        if (A > B) {
            printf("Round %d: Dice A wins!\n", i);
            c[0]++;
        } else if (A < B) {
            printf("Round %d: Dice B wins!\n", i);
            c[1]++;
        } else {
            printf("Round %d: It's a tie!\n", i);
            c[2]++;
        }
    }
    printf("Number of wins for Dice A: %d\n", c[0]);
    printf("Number of wins for Dice B: %d\n", c[1]);
    printf("Number of ties: %d\n", c[2]);

    return 0;
}
