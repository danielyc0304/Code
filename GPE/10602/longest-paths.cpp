#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    int n;

    for (int i = 1; cin >> n && n != 0; ++i) {
        int s;
        cin >> s;

        vector<vector<int>> edges(n + 1);

        int p, q;
        while (cin >> p >> q && (p != 0 || q != 0)) {
            edges[p].push_back(q);
        }

        vector<int> dist(n + 1, -1);

        stack<int> st;
        dist[s] = 0;
        st.push(s);
        while (st.empty() == false) {
            int from = st.top();
            st.pop();

            for (int to : edges[from]) {
                if (dist[to] < dist[from] + 1) {
                    dist[to] = dist[from] + 1;

                    st.push(to);
                }
            }
        }

        int maxDist = -1, farNode = s;
        for (int j = 1; j <= n; ++j) {
            if (dist[j] > maxDist ||
                (dist[j] == maxDist && j < farNode)) {
                maxDist = dist[j];
                farNode = j;
            }
        }

        cout << "Case " << i << ": The longest path from " << s
             << " has length " << maxDist << ", finishing at " << farNode
             << "." << endl;

        cout << endl;
    }
    return 0;
}
