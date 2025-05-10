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

        for (const string& str : strs) {
            if (str.find(prefix) != 0) {
                return false;
            }
        }

        return true;
    }

  public:
    string longestCommonPrefix(vector<string>& strs) {
        int minLen = INT_MAX;

        for (const string& str : strs) {
            minLen = min(minLen, (int)str.length());
        }

        int left = 0, right = minLen;

        // 對最長匹配長度做二分搜
        while (left <= right) {
            int middle = (left + right) / 2;

            if (isCommonPrefix(strs, middle) == true) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return strs[0].substr(0, right);
    }
};
// @lc code=end
