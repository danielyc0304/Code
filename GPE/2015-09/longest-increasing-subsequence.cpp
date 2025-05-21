#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    while (cin >> n) {
        vector<int> num(n);

        for (int i = 0; i < n; ++i) {
            cin >> num[i];
        }

        vector<int> dp(n, 1);

        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (num[i] > num[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
        }

        cout << *max_element(dp.begin(), dp.end()) << endl;
    }

    return 0;
}
