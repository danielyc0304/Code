#include <iostream>
using namespace std;

int main() {
    int H1, M1, H2, M2;
    scanf("%d %d %d %d", &H1, &M1, &H2, &M2);

    if (H1 > H2 || (H1 == H2 && M1 > M2)) {
        H2 += 24;
    }

    printf("%d\n", (H2 - H1) * 60 + (M2 - M1));

    return 0;
}
