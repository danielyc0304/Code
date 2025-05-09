/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 */

#include <iostream>
#include <stack>
using namespace std;

// @lc code=start
class Solution {
  public:
    int longestValidParentheses(string s) {
        stack<int> longestMatchPosition;
        int maxLen = 0;

        longestMatchPosition.push(-1);

        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '(') {
                longestMatchPosition.push(i);  // i還沒被匹配
            } else {
                longestMatchPosition.pop();

                // 空了代表前面的字串都不匹配了
                if (longestMatchPosition.empty() == true) {
                    longestMatchPosition.push(i);
                } else {
                    maxLen = max(maxLen, i - longestMatchPosition.top());
                }
            }
        }

        return maxLen;
    }
};
// @lc code=end
