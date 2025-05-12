/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    int lengthOfLastWord(string s) {
        int end = s.length() - 1;
        while (s[end] == ' ') {  // 直接判斷s[end--]==' '會跳過只有一個字的情況
            --end;
        }

        int start = end;
        while (start >= 0 && s[start] != ' ') {
            --start;
        }

        return end - start;
    }
};
// @lc code=end
