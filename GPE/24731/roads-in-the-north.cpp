#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

int maxDist, farNode;

void dfs(const unordered_map<int, vector<pair<int, int>>>& graph, int node,
         bool visited[], int dist) {
    visited[node] = true;

    if (dist > maxDist) {
        maxDist = dist;
        farNode = node;
    }

    for (const auto& [to, toDist] : graph.at(node)) {
        if (visited[to] == false) {
            dfs(graph, to, visited, dist + toDist);
        }
    }
}

int main() {
    while (true) {
        unordered_map<int, vector<pair<int, int>>>
            graph;  // {from,{to,distance}}

        string s;
        int maxNode = 0;

        while (getline(cin, s) && s.empty() == false) {
            stringstream ss(s);

            int from, to, dist;
            ss >> from >> to >> dist;
            graph[from].push_back({to, dist});
            graph[to].push_back({from, dist});

            maxNode = max(maxNode, max(from, to));
        }

        if (maxNode == 0) {
            break;  // 結束
        }

        bool visited[maxNode + 1];

        maxDist = 0;
        memset(visited, false, sizeof(visited));
        dfs(graph, 1, visited, 0);

        int start = farNode;
        maxDist = 0;
        memset(visited, false, sizeof(visited));
        dfs(graph, start, visited, 0);

        cout << maxDist << endl;
    }

    return 0;
}
