#include <iostream>
using namespace std;

int main() {
    int N;
    while (scanf("%d", &N) != EOF) {
        int sum = N;
        while (N >= 3) {
            sum += N / 3;
            N = N / 3 + N % 3;
        }

        printf("%d\n", (N == 2) ? sum + 1 : sum);
    }

    return 0;
}
