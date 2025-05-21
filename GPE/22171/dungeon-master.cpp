#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int z, x, y, time;
};

char dungeon[30][30][30];
bool visited[30][30][30];

int bfs(int z, int x, int y, int L, int R, int C) {
    const int dirs[6][3] = {{1, 0, 0},  {-1, 0, 0}, {0, 1, 0},
                            {0, -1, 0}, {0, 0, 1},  {0, 0, -1}};

    queue<Node> q;

    q.push({z, x, y, 0});
    visited[z][x][y] = true;

    while (q.empty() == false) {
        Node curr = q.front();
        q.pop();

        if (dungeon[curr.z][curr.x][curr.y] == 'E') {
            return curr.time;
        }

        for (auto [x, y, z] : dirs) {
            int newZ = curr.z + z;
            int newX = curr.x + x;
            int newY = curr.y + y;

            if (newZ < 0 || newZ >= L || newX < 0 || newX >= R || newY < 0 ||
                newY >= C) {
                continue;
            }
            if (dungeon[newZ][newX][newY] == '#' || visited[newZ][newX][newY]) {
                continue;
            }

            visited[newZ][newX][newY] = true;
            q.push({newZ, newX, newY, curr.time + 1});
        }
    }

    return -1;
}

int main() {
    int L, R, C;

    while (cin >> L >> R >> C && (L != 0 || R != 0 || C != 0)) {
        int startX, startY, startZ;

        for (int z = 0; z < L; ++z) {
            for (int x = 0; x < R; ++x) {
                for (int y = 0; y < C; ++y) {
                    cin >> dungeon[z][x][y];

                    if (dungeon[z][x][y] == 'S') {
                        startX = x;
                        startY = y;
                        startZ = z;
                    }

                    visited[z][x][y] = false;
                }
            }
        }

        int result = bfs(startZ, startX, startY, L, R, C);
        if (result != -1)
            cout << "Escaped in " << result << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }

    return 0;
}
