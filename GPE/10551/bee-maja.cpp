#include <iostream>
using namespace std;

int main() {
    const int dirs[7][2] = {{0, 1},  {-1, 1}, {-1, 0}, {0, -1},
                            {1, -1}, {1, 0},  {0, 1}};

    int n;

    while (cin >> n) {
        int x = 0, y = 0;
        --n;

        // 一開始只往下一格
        for (int layer = 1; n > 0; ++layer) {
            x += dirs[0][0];
            y += dirs[0][1];
            --n;

            // 第二個方向只走layer-1次
            for (int j = 0; n > 0 && j < layer - 1; --n, ++j) {
                x += dirs[1][0];
                y += dirs[1][1];
            }

            for (int dir = 2; dir < 7; ++dir) {
                for (int j = 0; n > 0 && j < layer; --n, ++j) {
                    x += dirs[dir][0];
                    y += dirs[dir][1];
                }
            }
        }

        cout << x << " " << y << endl;
    }

    return 0;
}