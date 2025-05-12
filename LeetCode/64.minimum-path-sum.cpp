/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = grid[0][0];
        for (int r = 1; r < m; ++r) {
            dp[r][0] = grid[r][0] + dp[r - 1][0];
        }
        for (int c = 1; c < n; ++c) {
            dp[0][c] = grid[0][c] + dp[0][c - 1];
        }

        for (int r = 1; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                dp[r][c] += grid[r][c] + min(dp[r - 1][c], dp[r][c - 1]);
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end
