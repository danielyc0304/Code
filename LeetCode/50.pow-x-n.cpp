/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    double myPow(double x, int n) {
        if (n < 0) {
            x = 1 / x;
        }
        long num = labs(n);

        double pow = 1;

        while (num > 0) {
            if (num % 2 == 1) {
                pow *= x;
            }

            x *= x;
            num /= 2;
        }

        return pow;
    }
};
// @lc code=end
