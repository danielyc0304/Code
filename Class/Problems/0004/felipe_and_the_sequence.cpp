#include <iostream>
using namespace std;

int main() {
    int S;
    scanf("%d", &S);
    // 每一項分子分母同乘sqrt(b)-sqrt(a)，分母變為0，分子變為sqrt(b)-sqrt(a)，化簡後得到sqrt(n+1)-sqrt(1)=S,
    // n=(S+1)^2-1
    printf("%ld\n", (long int)(S + 1) * (S + 1) - 1);

    return 0;
}
