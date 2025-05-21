#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    const int coins[11] = {2000, 1000, 400, 200, 100, 40, 20, 10, 4, 2, 1};

    vector<long> dp(6001, 0);

    dp[0] = 1;
    for (int coin : coins) {
        for (int i = coin; i <= 6000; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    double amount;
    while (cin >> amount && amount != 0) {
        cout << fixed << setprecision(2) << setw(6) << amount << setw(17)
             << dp[(int)(amount * 20)] << endl;
    }

    return 0;
}
