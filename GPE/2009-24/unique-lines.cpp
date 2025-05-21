#include <iostream>
#include <set>
#include <vector>
using namespace std;

int gcd(int a, int b) { return (b == 0) ? abs(a) : gcd(b, a % b); }

tuple<int, int, int> normalize(int a, int b, int c) {
    int g = gcd(a, gcd(b, c));
    if (g > 1) {
        a /= g;
        b /= g;
        c /= g;
    }

    if (a < 0 || (a == 0 && b < 0)) {
        a *= -1;
        b *= -1;
        c *= -1;
    }

    return {a, b, c};
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        int N;
        cin >> N;

        vector<pair<int, int>> points;  // {x,y}

        while (N--) {
            int x, y;
            cin >> x >> y;

            points.push_back({x, y});
        }

        set<tuple<int, int, int>> lines;  // {a,b,c}

        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                // 將(y-y1)/(y2-y1)=(x-x1)/(x2-x1)移成ax+by+c=0的形式
                int x1 = points[i].first, y1 = points[i].second,
                    x2 = points[j].first, y2 = points[j].second;

                int a = y2 - y1, b = x1 - x2, c = x1 * y2 - x2 * y1;

                lines.insert(normalize(a, b, c));
            }
        }

        cout << lines.size() << endl;
    }

    return 0;
}
