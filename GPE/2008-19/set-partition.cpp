#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

bool cmp(const vector<long>& a, const vector<long>& b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    return a < b;
}

vector<vector<long>> getSubsets(const vector<long>& nums, int total) {
    int n = nums.size();
    long half = total / 2;
    vector<vector<long>> subsets;

    // bitmask
    for (int mask = 1; mask < (1 << n); ++mask) {
        long sum = 0;
        vector<long> subset;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                sum += nums[i];
                if (sum > half) {
                    break;
                }

                subset.push_back(nums[i]);
            }
        }

        if (sum == half) {
            subsets.push_back(subset);
        }
    }

    sort(subsets.begin(), subsets.end(), cmp);

    return subsets;
}

int main() {
    string s;

    while (getline(cin, s) && s != ".") {
        vector<long> nums;

        stringstream ss(s.substr(1, s.size() - 2));
        long num, sum = 0;

        while (ss >> num) {
            sum += num;
            nums.push_back(num);
        }

        vector<vector<long>> result = getSubsets(nums, sum);

        if (result.empty() == false) {
            cout << result.size() << " subsets." << endl;
            for (const auto& subset : result) {
                cout << "{";
                for (int i = 0; i < subset.size(); ++i) {
                    if (i > 0) {
                        cout << " ";
                    }
                    cout << subset[i];
                }
                cout << "}" << endl;
            }
        } else {
            cout << "No such subset" << endl;
        }
        cout << endl;
    }

    return 0;
}
