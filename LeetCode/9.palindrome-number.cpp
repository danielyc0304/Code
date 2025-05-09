/*
 * @lc app=leetcode id=9 lang=cpp
 *
 * [9] Palindrome Number
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isPalindrome(int x) {
        // 負數或尾數為0就一定不是palindrome
        if (x < 0 || (x > 0 && x % 10 == 0)) {
            return false;
        }

        int y = 0;

        while (y < x) {
            y = y * 10 + x % 10;
            x /= 10;
        }

        return (x == y || x == y / 10);
    }
};
// @lc code=end
