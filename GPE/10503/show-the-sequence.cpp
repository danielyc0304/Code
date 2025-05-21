#include <iostream>
#include <vector>
using namespace std;

int parseNumber(const string& s, int& idx) {
    int sign = (s[idx] != '-') ? 1 : -1;
    idx += (s[idx] == '-');
    int num = 0;

    while (isdigit(s[idx]) == true) {
        num = 10 * num + (s[idx++] - '0');
    }

    return sign * num;
}

vector<int> parse(const string& s, int idx, int N) {
    ++idx;  // [

    int num = parseNumber(s, idx);

    // []裡面只有一個值
    if (s[idx] == ']') {
        ++idx;

        return vector<int>(N, num);
    }

    char op = s[idx++];
    vector<int> sub = parse(s, idx++, N);

    vector<int> result(N);

    if (op == '+') {
        result[0] = num;

        for (int i = 1; i < N; ++i) {
            result[i] = result[i - 1] + sub[i - 1];
        }
    } else {
        result[0] = num * sub[0];

        for (int i = 1; i < N; ++i) {
            result[i] = result[i - 1] * sub[i];
        }
    }

    return result;
}

int main() {
    string s;
    int N;

    while (cin >> s >> N) {
        vector<int> result = parse(s, 0, N);

        for (int num : result) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
