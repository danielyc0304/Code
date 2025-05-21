#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n--) {
        int M;
        cin >> M;

        vector<pair<int, int>> intervals;  // {L,R}

        int L, R;
        while (cin >> L >> R && (L != 0 || R != 0)) {
            if (R < 0 || L > M) {
                continue;
            }
            intervals.push_back({L, R});
        }

        bool found = true;
        vector<pair<int, int>> result;

        int curr = 0, i = 0;
        while (curr < M) {
            int farthest = curr;
            pair<int, int> bestInterval;

            while (i < intervals.size() && intervals[i].first <= curr) {
                if (intervals[i].second > farthest) {
                    farthest = intervals[i].second;
                    bestInterval = intervals[i];
                }

                ++i;
            }

            if (farthest == curr) {
                found = false;

                break;
            }

            curr = farthest;
            result.push_back(bestInterval);
        }

        if (found == true) {
            cout << result.size() << endl;
            for (const auto& interval : result) {
                cout << interval.first << " " << interval.second << endl;
            }
        } else {
            cout << 0 << endl;
        }
        cout << endl;
    }

    return 0;
}
