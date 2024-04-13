#include <iostream>
using namespace std;

int main() {
    int k;
    scanf("%d", &k);

    printf("%d\n", (k / 2) * (k / 2 + (k % 2 == 0 ? 0 : 1)));

    return 0;
}
