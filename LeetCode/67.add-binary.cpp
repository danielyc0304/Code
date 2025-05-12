/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    string addBinary(string a, string b) {
        int i = a.length() - 1, j = b.length() - 1;
        int carry = 0;
        string result;

        while (i >= 0 || j >= 0 || carry) {
            if (i >= 0) {
                carry += a[i--] - '0';
            }
            if (j >= 0) {
                carry += b[j--] - '0';
            }

            result += carry % 2 + '0';
            carry /= 2;
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
