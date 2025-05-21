#include <iostream>
#include <vector>
using namespace std;

bool isValid(const vector<vector<int>>& board, int row, int col, int num) {
    for (int r = 0; r < 9; ++r) {
        if (board[r][col] == num) {
            return false;
        }
    }

    for (int c = 0; c < 9; ++c) {
        if (board[row][c] == num) {
            return false;
        }
    }

    int bRow = row / 3 * 3, bCol = col / 3 * 3;
    for (int r = bRow; r <= bRow + 2; ++r) {
        for (int c = bCol; c <= bCol + 2; ++c) {
            if (board[r][c] == num) {
                return false;
            }
        }
    }

    return true;
}

bool backtrack(vector<vector<int>>& board, int row, int col) {
    if (row == 9) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }

        return true;
    }

    int nextRow = row + (col + 1) / 9;
    int nextCol = (col + 1) % 9;

    if (board[row][col] != 0) {
        return backtrack(board, nextRow, nextCol);
    }

    for (int num = 1; num <= 9; ++num) {
        if (isValid(board, row, col, num) == true) {
            board[row][col] = num;

            if (backtrack(board, nextRow, nextCol) == true) {
                return true;
            }

            board[row][col] = 0;
        }
    }

    return false;
}

int main() {
    int N;
    cin >> N;

    while (N--) {
        vector<vector<int>> board;

        for (int r = 0; r < 9; ++r) {
            vector<int> row;

            for (int c = 0; c < 9; ++c) {
                int num;
                cin >> num;
                row.push_back(num);
            }

            board.push_back(row);
        }

        bool found = backtrack(board, 0, 0);

        if (found == false) {
            cout << "NO" << endl;
        }
    }

    return 0;
}
