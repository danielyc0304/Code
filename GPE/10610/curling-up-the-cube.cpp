#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// 從上往下看(Up,Down,Front,Right,Back,Left)
// 0->往上、1->往右、2->往下、3->往左
// {現在的面+方向,走過去對應到的面}
const unordered_map<string, string> transition = {
    {"U0", "F"}, {"U1", "R"}, {"U2", "B"}, {"U3", "L"}, {"D0", "B"},
    {"D1", "R"}, {"D2", "F"}, {"D3", "L"}, {"F0", "D"}, {"F1", "R"},
    {"F2", "U"}, {"F3", "L"}, {"B0", "U"}, {"B1", "R"}, {"B2", "D"},
    {"B3", "L"}, {"L0", "U"}, {"L1", "B"}, {"L2", "D"}, {"L3", "F"},
    {"R0", "U"}, {"R1", "F"}, {"R2", "D"}, {"R3", "B"}};

int paper[6][6];
bool visited[6][6];

bool dfs(int i, int j, string currFace,
         unordered_map<string, pair<int, int>>& assigned) {
    if (assigned.find(currFace) != assigned.end()) {
        return (assigned[currFace] == make_pair(i, j));
    }

    if (visited[i][j] == true) {
        return false;
    }

    visited[i][j] = true;
    assigned[currFace] = {i, j};

    for (int dir = 0; dir < 4; ++dir) {
        int newI = i + dirs[dir][0], newJ = j + dirs[dir][1];

        if (newI < 0 || newI >= 6 || newJ < 0 || newJ >= 6) {
            continue;
        }

        if (paper[newI][newJ] == 1) {
            string newFace = transition.at(currFace + to_string(dir));

            if (dfs(newI, newJ, newFace, assigned) == false) {
                return false;
            }
        }
    }

    return true;
}

bool isValid() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            if (paper[i][j] == true) {
                unordered_map<string, pair<int, int>> assigned;  // {面,座標}
                memset(visited, false, sizeof(visited));

                if (dfs(i, j, "U", assigned) == true && assigned.size() == 6) {
                    return true;
                }
            }
        }
    }

    return false;
}

int main() {
    int n;
    cin >> n;

    while (n--) {
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 6; ++j) {
                cin >> paper[i][j];
            }
        }

        cout << ((isValid() == true) ? "correct" : "incorrect") << endl;
    }

    return 0;
}
