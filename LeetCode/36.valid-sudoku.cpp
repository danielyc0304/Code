/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 */

#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9] = {0}, cols[9] = {0}, boxes[9] = {0};

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                int move = board[r][c] - '1';
                int mask = 1 << move;
                int b = (r / 3) * 3 + c / 3;

                if (rows[r] & mask || cols[c] & mask || boxes[b] & mask) {
                    return false;
                }

                rows[r] |= mask;
                cols[c] |= mask;
                boxes[b] |= mask;
            }
        }

        return true;
    }
};
// @lc code=end
