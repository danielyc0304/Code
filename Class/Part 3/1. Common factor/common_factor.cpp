#include <iostream>
using namespace std;

int GCD(int a, int b) {
    if (b == 0) {
        return a;
    }

    return GCD(b, a % b);
}

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int num = GCD(a, b);
    for (int i = 1; i <= num; i++) {
        if (num % i == 0) {
            printf("%d ", i);
        }
    }
    printf("\n");

    return 0;
}
