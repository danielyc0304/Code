/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));

        dp[0][0] = 1;
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (obstacleGrid[r][c] == 1) {
                    dp[r][c] = 0;
                } else {
                    if (r > 0) {
                        dp[r][c] += dp[r - 1][c];
                    }
                    if (c > 0) {
                        dp[r][c] += dp[r][c - 1];
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
// @lc code=end
