#include <iostream>
using namespace std;

int main() {
    int a, b;
    scanf("%d %d", &a, &b);

    int num = abs(a - b);

    printf("%d\n", min(num, 100 - num));

    return 0;
}
