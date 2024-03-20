#include <iostream>
using namespace std;

int main() {
    int year, month;
    scanf("%d %d", &year, &month);

    int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2) {
        printf("%d\n",
               28 + ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0));
    } else {
        printf("%d\n", days[month - 1]);
    }

    return 0;
}
