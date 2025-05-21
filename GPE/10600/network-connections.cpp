#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

vector<int> parent;

int find(int a) {
    if (parent[a] != a) {
        parent[a] = find(parent[a]);  // 把所有節點都指向根節點
    }

    return parent[a];
}

void unite(int a, int b) { parent[find(a)] = find(b); }

int main() {
    int n;
    cin >> n;

    while (n--) {
        int num;
        cin >> num;
        cin.ignore();

        parent.resize(num + 1);
        for (int i = 1; i <= num; ++i) {
            parent[i] = i;
        }

        int success = 0, fail = 0;

        string s;
        while (getline(cin, s) && s.empty() == false) {
            stringstream ss(s);
            char op;
            int a, b;

            ss >> op >> a >> b;

            if (op == 'c') {
                unite(a, b);
            } else {
                if (find(a) == find(b)) {
                    ++success;
                } else {
                    ++fail;
                }
            }
        }

        cout << success << "," << fail << endl;
    }

    return 0;
}
