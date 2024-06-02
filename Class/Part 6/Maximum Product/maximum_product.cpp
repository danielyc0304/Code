#include <iostream>
using namespace std;

int main() {
    int N;
    for (int i = 1; scanf("%d", &N) != EOF; i++) {
        int S[N];
        for (int i = 0; i < N; i++) {
            scanf("%d", &S[i]);
        }

        long int max_num = 0;
        for (int i = 0; i < N; i++) {
            long int product = 1;
            for (int j = i; j < N; j++) {
                product *= S[j];
                max_num = max(max_num, product);
            }
        }

        printf("Case #%d: The maximum product is %ld.\n\n", i, max_num);
    }

    return 0;
}
