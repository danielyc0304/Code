/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        }

        if (dividend == INT_MIN &&
            divisor == -1) {  // result存不下，直接當例外情況
            return INT_MAX;
        }
        if (divisor == 1) {
            return dividend;
        }

        int a, extraA, b, extraB;

        if (dividend == INT_MIN) {
            a = INT_MAX;
            extraA = 1;
        } else {
            a = abs(dividend);
            extraA = 0;
        }

        if (divisor == INT_MIN) {
            b = INT_MAX;
            extraB = 1;
        } else {
            b = abs(divisor);
            extraB = 0;
        }

        int result = 0;

        while (((long)a + extraA) >= ((long)b + extraB)) {
            int shift = 0;

            while (((long)a + extraA) >= (((long)b + extraB) << (shift + 1))) {
                ++shift;
            }

            result += 1 << shift;
            a -= ((long)b + extraB) << shift;
            extraA -= (a < 0);
        }

        bool isPositive = ((dividend > 0) == (divisor > 0));

        return (isPositive == true) ? result : -result;
    }
};
// @lc code=end
