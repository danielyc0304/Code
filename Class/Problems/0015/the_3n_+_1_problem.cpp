#include <iostream>
using namespace std;

int main() {
    int i, j;
    while (scanf("%d %d", &i, &j) != EOF) {
        int max_c = 0;
        for (int k = min(i, j); k <= max(i, j); k++) {
            int num = k, c = 1;
            while (num != 1) {
                if (num % 2 == 0) {
                    num /= 2;
                } else {
                    num = 3 * num + 1;
                }

                c++;
            }

            max_c = max(max_c, c);
        }

        printf("%d %d %d\n", i, j, max_c);
    }

    return 0;
}
