#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;

    while (cin >> N && N != 0) {
        for (int m = 1; m < N; ++m) {
            vector<bool> closed(N, false);
            int left = N - 1, curr = 0;

            closed[0] = true;

            while (left > 1) {
                int c = 0;

                while (c < m) {
                    curr = (curr + 1) % N;  // 一次只走一步

                    if (closed[curr] == false) {  // 還沒關閉的區域才算往後一個
                        ++c;
                    }
                }

                closed[curr] = true;
                --left;

                // 如果已經關閉13號區域就不符合條件了，提早退出
                if (closed[12] == true) {
                    break;
                }
            }

            if (closed[12] == false) {
                cout << m << endl;

                break;
            }
        }
    }

    return 0;
}
