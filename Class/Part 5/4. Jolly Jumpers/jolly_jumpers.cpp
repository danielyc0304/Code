#include <iostream>
using namespace std;

string solution(int *a, int n) {
    bool exist[n];
    for (int i = 1; i < n; i++) {
        exist[i] = false;
    }
    for (int i = 1; i < n; i++) {
        if (exist[abs(a[i] - a[i - 1])] == true) {
            return "Not jolly";
        }

        exist[abs(a[i] - a[i - 1])] = true;
    }

    return "Jolly";
}

int main() {
    int n;
    while (scanf("%d", &n) != EOF) {
        int a[n];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        printf("%s\n", solution(a, n).c_str());
    }

    return 0;
}
