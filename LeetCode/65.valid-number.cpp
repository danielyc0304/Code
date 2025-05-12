/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isNumber(string s) {
        bool isNum = false, isDot = false, isE = false;

        for (int i = 0; i < s.length(); ++i) {
            if (isdigit(s[i])) {
                isNum = true;
            } else if (s[i] == '+' || s[i] == '-') {
                // 正負號只能出現在開頭或e後面
                if (i > 0 && s[i - 1] != 'e' && s[i - 1] != 'E') {
                    return false;
                }
            } else if (s[i] == '.') {
                // 小數點只能出現一次且不能出現在e後面，前面可以沒有數字
                if (isDot == true || isE == true) {
                    return false;
                }

                isDot = true;
                // 小數點後面可以沒有數字
            } else if (s[i] == 'e' || s[i] == 'E') {
                // e只能出現一次且出現在數字後面
                if (isE == true || isNum == false) {
                    return false;
                }

                isE = true;
                isNum = false;  // e後面要有數字
            } else {
                return false;
            }
        }

        return isNum;
    }
};
// @lc code=end
