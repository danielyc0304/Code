#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);

    int sum = 0;
    for (int i = 1; i <= n; i++) {
        if (i % 3 == 0 || i % 5 == 0 || i % 7 == 0) {
            sum += i;
        }
    }
    printf("%d\n", sum);

    return 0;
}
