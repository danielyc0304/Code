#include <iostream>
using namespace std;

string solution(string s) {
    string result = "";
    for (int i = 0; i < s.length(); i++) {
        if (i % 2 == 0) {
            result += toupper(s[i]);
        } else {
            result += tolower(s[i]);
        }
    }
    return result;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == "stop") {
            break;
        }
        printf("%s\n", solution(s).c_str());
    }

    return 0;
}
