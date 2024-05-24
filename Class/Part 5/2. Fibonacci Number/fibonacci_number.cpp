#include <iostream>
using namespace std;

int calculateFibonacci(int n) {
    if (n == 1 || n == 2) {
        return 1;
    }

    return calculateFibonacci(n - 1) + calculateFibonacci(n - 2);
}

int main() {
    int n;
    scanf("%d", &n);

    printf("%d\n", calculateFibonacci(n));

    return 0;
}
