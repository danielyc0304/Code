#include <iostream>
using namespace std;

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int n;
        scanf("%d", &n);

        int min_num = 100, max_num = 0;
        for (int j = 0; j < n; j++) {
            int num;
            scanf("%d", &num);

            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }

        printf("%d\n", 2 * (max_num - min_num));
    }

    return 0;
}
