#include <iostream>
using namespace std;

int main() {
    int N;
    scanf("%d", &N);

    long int line = N / 2 + 1;
    long int last_odd = 2 * line * line - 1;  // 字尾會是第line * line個奇數

    printf("%ld\n", 3 * last_odd - 6);

    return 0;
}
