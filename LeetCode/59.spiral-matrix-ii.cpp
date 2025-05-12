/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> generateMatrix(int n) {
        int c = 1;
        int top = 0, bottom = n - 1, left = 0, right = n - 1;
        vector<vector<int>> result(n, vector<int>(n, 0));

        while (c <= n * n) {
            for (int i = left; i <= right; ++i) {
                result[top][i] = c++;
            }
            ++top;
            if (c > n * n) {
                break;
            }

            for (int i = top; i <= bottom; ++i) {
                result[i][right] = c++;
            }
            --right;

            for (int i = right; i >= left; --i) {
                result[bottom][i] = c++;
            }
            --bottom;
            if (c > n * n) {
                break;
            }

            for (int i = bottom; i >= top; --i) {
                result[i][left] = c++;
            }
            ++left;
        }

        return result;
    }
};
// @lc code=end
