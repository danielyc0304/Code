/*
 * @lc app=leetcode id=44 lang=cpp
 *
 * [44] Wildcard Matching
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {  // 選到*
                    // 第一個條件式：當次不匹配
                    // 第二個條件式：當次匹配
                    dp[i][j] = dp[i][j - 1] || (i > 0 && dp[i - 1][j]);
                } else if (
                    i > 0 &&
                    (p[j - 1] == '?' ||
                     s[i - 1] ==
                         p[j - 1])) {  // 匹配，i>0是因為就算是'?'也要匹配一個字
                    dp[i][j] = dp[i - 1][j - 1];
                } else {  // 不匹配
                    dp[i][j] = false;
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
