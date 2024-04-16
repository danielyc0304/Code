#include <iostream>
using namespace std;

int main() {
    int n;
    for (int i = 1; scanf("%d", &n) != EOF; i++) {
        if (n == 0) {
            break;
        }

        int k[n];
        int sum = 0;
        for (int j = 0; j < n; j++) {
            scanf("%d", &k[j]);

            sum += k[j];
        }

        int avg = sum / n;
        int c = 0;
        for (int j = 0; j < n; j++) {
            c += abs(k[j] - avg);
        }

        printf("Set #%d\n", i);
        printf("The minimum number of moves is %d.\n", c / 2);
        printf("\n");
    }

    return 0;
}
