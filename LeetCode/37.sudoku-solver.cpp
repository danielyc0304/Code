/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    bool isValid(const vector<vector<char>>& board, int row, int col,
                 char num) {
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

    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9) {
            return true;
        }

        int nextRow = row + (col + 1) / 9;
        int nextCol = (col + 1) % 9;

        if (board[row][col] != '.') {
            return backtrack(board, nextRow, nextCol);
        }

        for (char num = '1'; num <= '9'; ++num) {
            if (isValid(board, row, col, num) == true) {
                board[row][col] = num;

                if (backtrack(board, nextRow, nextCol) == true) {
                    return true;
                }

                board[row][col] = '.';
            }
        }

        return false;
    }

  public:
    void solveSudoku(vector<vector<char>>& board) { backtrack(board, 0, 0); }
};
// @lc code=end
