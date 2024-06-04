#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int c = 0;
    while (n != 1) {
        c += n / 2;
        n = n / 2 + n % 2;
    }

    printf("%d\n", c);

    return 0;
}
