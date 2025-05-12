/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
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

    void backtrack(int row, int n, vector<string>& board,
                   vector<vector<string>>& result) {
        if (row == n) {
            result.push_back(board);

            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(row, col, n, board) == true) {
                board[row][col] = 'Q';

                backtrack(row + 1, n, board, result);

                board[row][col] = '.';
            }
        }
    }

  public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n);
        vector<vector<string>> result;

        // 直接在vector初始化會很慢
        string s(n, '.');
        for (int i = 0; i < n; ++i) {
            board[i] = s;
        }

        // 在函式裡面用board.size()代替n會變慢
        backtrack(0, n, board, result);

        return result;
    }
};
// @lc code=end
