/*
Problem:
https://www.hackerearth.com/practice/data-structures/arrays/1-d/practice-problems/algorithm/howie-and-the-menus-2-48359fe4/
Title: James and the menus
Time: 2024-02-10 21:08:23 Add
*/

#include <iostream>
using namespace std;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int A[n][m];
    int max_num[m];
    double average_price[n];
    for (int i = 0; i < m; i++) {
        max_num[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        double sum = 0;

        for (int j = 0; j < m; j++) {
            scanf("%d", &A[i][j]);

            sum += A[i][j];
            max_num[j] = max(max_num[j], A[i][j]);
        }

        average_price[i] = sum / m;
    }

    int i = 0, max_c = 0, max_average_price = 0;
    for (int j = 0; j < n; j++) {
        int c = 0;

        for (int k = 0; k < m; k++) {
            if (A[j][k] == max_num[k]) {
                c++;
            }
        }

        if (c > max_c || (c == max_c && average_price[j] > max_average_price)) {
            i = j, max_c = c, max_average_price = average_price[j];
        }
    }

    printf("%d\n", i + 1);

    return 0;
}
