/*
 * @lc app=leetcode id=22 lang=cpp
 *
 * [22] Generate Parentheses
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    void dfs(int open, int close, int n, string s, vector<string>& result) {
        if (open == close && open + close == 2 * n) {
            result.push_back(s);

            return;
        }

        if (open < n) {
            dfs(open + 1, close, n, s + "(", result);
        }

        if (open > close) {
            dfs(open, close + 1, n, s + ")", result);
        }
    }

  public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;

        dfs(0, 0, n, "", result);

        return result;
    }
};
// @lc code=end
