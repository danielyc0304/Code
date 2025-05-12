/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    bool isValid(int row, int col, int n, const vector<string>& board) {
        // 左上
        int r = row - 1, c = col - 1;
        while (r >= 0 && c >= 0) {
            if (board[r--][c--] == 'Q') {
                return false;
            }
        }

        // 上
        r = row - 1;
        while (r >= 0) {
            if (board[r--][col] == 'Q') {
                return false;
            }
        }

        // 右上
        r = row - 1, c = col + 1;
        while (r >= 0 && c < n) {
            if (board[r--][c++] == 'Q') {
                return false;
            }
        }

        return true;
    }

    int backtrack(int row, int n, vector<string>& board) {
        if (row == n) {
            return 1;
        }

        int c = 0;

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, n, board) == true) {
                board[row][col] = 'Q';

                c += backtrack(row + 1, n, board);

                board[row][col] = '.';
            }
        }

        return c;
    }

  public:
    int totalNQueens(int n) {
        vector<string> board(n);

        string s(n, '.');
        for (int i = 0; i < n; ++i) {
            board[i] = s;
        }

        // 在函式裡面用board.size()代替n會變慢
        return backtrack(0, n, board);
    }
};
// @lc code=end
