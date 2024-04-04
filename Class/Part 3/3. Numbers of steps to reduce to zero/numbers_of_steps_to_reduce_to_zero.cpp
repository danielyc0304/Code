#include <iostream>
using namespace std;

int main() {
    int num;
    scanf("%d", &num);

    int c = 0;
    while (num != 0) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num--;
        }

        c++;
    }
    printf("%d\n", c);

    return 0;
}
