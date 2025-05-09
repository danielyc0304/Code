/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    // https://leetcode.com/problems/regular-expression-matching/solutions/3401751/detailed-explaination-with-pictures-in-c-java-python-dp-bottom-up-tabulation/?source=vscode
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        bool dp[m + 1][n + 1];  // dp[i][j]代表s[0~i-1]和p[0~j-1]是否匹配

        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for (int i = 0; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {  // 選到*
                    // 第一個條件式：當次不匹配
                    // 第二個條件式：當次匹配，且前一個狀態的字串還是匹配狀態
                    dp[i][j] = dp[i][j - 2] ||
                               (i > 0 && dp[i - 1][j] &&
                                (s[i - 1] == p[j - 2] || p[j - 2] == '.'));
                } else {
                    dp[i][j] = (i > 0 && dp[i - 1][j - 1] &&
                                (s[i - 1] == p[j - 1] || p[j - 1] == '.'));
                }
            }
        }

        return dp[m][n];
    }
};
// @lc code=end
