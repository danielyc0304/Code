#include <iostream>
#include <vector>
using namespace std;

int main() {
    string s;
    vector<string> words;

    while (getline(cin, s) && s != "0") {
        int i = 0;

        while (i < s.length()) {
            if (isdigit(s[i]) == true) {
                int num = 0;

                while (i < s.length() && isdigit(s[i]) == true) {
                    num = 10 * num + (s[i++] - '0');
                }

                string word = words[num - 1];

                cout << word;

                words.erase(words.begin() + num - 1);
                words.insert(words.begin(), word);
            } else if (isalpha(s[i]) == true) {
                string word;

                while (i < s.length() && isalpha(s[i]) == true) {
                    word += s[i++];
                }

                cout << word;

                words.insert(words.begin(), word);
            } else {
                cout << s[i++];
            }
        }

        cout << endl;
    }

    return 0;
}
