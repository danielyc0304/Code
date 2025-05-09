/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Find the Index of the First Occurrence in a String
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    int strStr(string haystack, string needle) {
        int m = haystack.length(), n = needle.length();

        for (int i = 0; i <= m - n; ++i) {
            if (haystack.substr(i, n) == needle) {
                return i;
            }
        }

        return -1;
    }
};
// @lc code=end
