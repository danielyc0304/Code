#include <iostream>
using namespace std;

string reverseStringRemoveDuplicate(string s) {
    bool existed[26] = {false};
    string duplicate_removed = "";
    for (int i = 0; i < s.length(); i++) {
        if (existed[int(s[i]) - 97] == false) {
            duplicate_removed += s[i];
            existed[int(s[i]) - 97] = true;
        }
    }

    string reversed = "";
    for (int i = duplicate_removed.length() - 1; i >= 0; i--) {
        reversed += duplicate_removed[i];
    }

    return reversed;
}

int main() {
    string s;
    while (getline(cin, s)) {
        if (s == "stop") {
            break;
        }

        printf("%s\n", reverseStringRemoveDuplicate(s).c_str());
    }

    return 0;
}
