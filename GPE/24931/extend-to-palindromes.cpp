#include <iostream>
#include <vector>
using namespace std;

// https://www.youtube.com/watch?v=af1oqpnH1vA
// KMP algorithm

vector<int> buildNext(const string& s) {
    vector<int> next;

    next.push_back(0);

    for (int i = 1; i < s.size(); ++i) {
        int prev = next[i - 1];

        while (prev > 0 && s[i] != s[prev]) {
            prev = next[prev - 1];
        }

        if (s[i] == s[prev]) {
            ++prev;
        }

        next.push_back(prev);
    }

    return next;
}

int main() {
    string s;

    while (getline(cin, s)) {
        string revS = s;

        reverse(revS.begin(), revS.end());

        string combineS = revS + "#" + s;
        vector<int> next = buildNext(combineS);

        int toAdd = s.length() - next.back();
        string result = s + revS.substr(next.back(), toAdd);

        cout << result << endl;
    }

    return 0;
}
