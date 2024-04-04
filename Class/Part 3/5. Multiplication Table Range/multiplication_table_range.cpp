#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= 9; i++) {
        for (int j = 2; j <= n; j++) {
            if (j != 2) {
                printf("  ");
            }
            printf("%d * %d = %2d", j, i, i * j);
        }
        printf("\n");
    }

    return 0;
}
