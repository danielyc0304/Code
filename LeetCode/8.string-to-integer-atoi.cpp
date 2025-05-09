/*
 * @lc app=leetcode id=8 lang=cpp
 *
 * [8] String to Integer (atoi)
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    int myAtoi(string s) {
        int i = 0;

        while (i < s.length() && s[i] == ' ') {
            ++i;
        }

        if (i == s.length()) {
            return 0;
        }

        int sign = 1;

        if (s[i] == '-') {
            sign = -1;
            ++i;
        } else if (s[i] == '+') {
            ++i;
        }

        int result = 0;

        while (i < s.length() && isdigit(s[i])) {
            if (result > INT_MAX / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            if (result == INT_MAX / 10) {
                if (sign == 1 && s[i] - '0' >= 7) {
                    return INT_MAX;
                }
                // 因為這題的sign是分開在result外面的，所以存負數時尾數為8就會溢位
                if (sign == -1 && s[i] - '0' >= 8) {
                    return INT_MIN;
                }
            }

            result = result * 10 + (s[i] - '0');
            ++i;
        }

        return sign * result;
    }
};
// @lc code=end
