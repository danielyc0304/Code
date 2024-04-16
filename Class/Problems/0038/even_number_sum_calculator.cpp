#include <iostream>
using namespace std;

int main() {
    int num;
    int sum = 0;
    while (scanf("%d", &num) != EOF) {
        if (num < 0) {
            printf("%d\n", sum);

            break;
        }

        if (num % 2 == 0) {
            sum += num;
        }
    }

    return 0;
}
