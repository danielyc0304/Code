#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;

    while (cin >> n && n != 0) {
        vector<int> nums;

        while (n--) {
            int num;
            cin >> num;
            nums.push_back(num);
        }

        sort(nums.begin(), nums.end());

        unordered_map<int, vector<pair<int, int>>> sumAB;  // {a,b}

        for (int a = 0; a < nums.size(); ++a) {
            for (int b = a + 1; b < nums.size(); ++b) {
                sumAB[nums[a] + nums[b]].push_back({a, b});
            }
        }

        bool found = false;

        for (int d = nums.size() - 1; d >= 0 && found == false; --d) {
            for (int c = 0; c < nums.size() && found == false; ++c) {
                if (c == d) {
                    continue;
                }

                int target = nums[d] - nums[c];
                if (sumAB.find(target) != sumAB.end()) {
                    for (const auto& [a, b] : sumAB[target]) {
                        if (a != c && a != d && b != c && b != d) {
                            cout << nums[d] << endl;

                            found = true;
                            break;
                        }
                    }
                }
            }
        }

        if (found == false) {
            cout << "no solution" << endl;
        }
    }

    return 0;
}
