/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    int mySqrt(int x) {
        int left = 0, right = x;

        while (left <= right) {
            int middle = (left + right) / 2;
            long square = (long)middle * middle;

            if (square == x) {
                return middle;
            } else if (square < x) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return right;
    }
};
// @lc code=end
