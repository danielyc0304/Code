/*
 * @lc app=leetcode id=14 lang=cpp
 *
 * [14] Longest Common Prefix
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    bool isCommonPrefix(const vector<string>& strs, int len) {
        string prefix = strs[0].substr(0, len);

        for (int i = 1; i < strs.size(); ++i) {
            if (strs[i].find(prefix) != 0) {
                return false;
            }
        }

        return true;
    }

  public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;

        for (int i = 0; i < strs.size(); ++i) {
            minLen = min(minLen, (int)strs[i].length());
        }

        int left = 0, right = minLen;

        // 對最長匹配長度做二分搜
        while (left <= right) {
            int middle = (left + right) / 2;

            if (isCommonPrefix(strs, middle)) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return strs[0].substr(0, (left + right) / 2);
    }
};
// @lc code=end
