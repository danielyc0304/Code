#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int num, frequency;
        scanf("%d %d", &num, &frequency);

        for (int j = 0; j < frequency; j++) {
            for (int k = 1; k <= num; k++) {
                for (int l = 0; l < k; l++) {
                    printf("%d", k);
                }
                printf("\n");
            }
            for (int k = num - 1; k > 0; k--) {
                for (int l = 0; l < k; l++) {
                    printf("%d", k);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

    return 0;
}
