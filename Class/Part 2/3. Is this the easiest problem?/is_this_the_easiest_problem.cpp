#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int length[3];
    for (int i = 0; i < 3; i++) {
        scanf("%d", &length[i]);
    }

    sort(length, length + 3);

    if (length[0] > 0 && length[1] > 0 && length[2] > 0 &&
        (long int)length[0] + length[1] > length[2]) {
        if (length[0] == length[1] && length[1] == length[2]) {
            printf("Equilateral\n");
        } else if (length[0] == length[1] || length[1] == length[2]) {
            printf("Isosceles\n");
        } else {
            printf("Scalene\n");
        }
    } else {
        printf("Invalid\n");
    }

    return 0;
}
