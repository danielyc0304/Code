#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool isValid(const vector<int>& weights, int total) {
    if (total % 2 != 0) {
        return false;
    }

    int half = total / 2;
    vector<bool> dp(half + 1, false);

    dp[0] = true;
    for (int weight : weights) {
        for (int j = half; j >= weight; --j) {
            dp[j] = dp[j] || dp[j - weight];
        }
    }

    return dp[half];
}

int main() {
    int m;
    cin >> m;
    cin.ignore();

    while (m--) {
        vector<int> weights;
        string s;

        getline(cin, s);

        stringstream ss(s);
        int sum = 0, weight;

        while (ss >> weight) {
            sum += weight;
            weights.push_back(weight);
        }

        cout << ((isValid(weights, sum) == true) ? "YES" : "NO") << endl;
    }

    return 0;
}
