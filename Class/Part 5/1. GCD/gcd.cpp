#include <iostream>
using namespace std;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return gcd(b, a % b);
}

int main() {
    int num1, num2;
    scanf("%d %d", &num1, &num2);

    printf("%d\n", gcd(num1, num2));

    return 0;
}
