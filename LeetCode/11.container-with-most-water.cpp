/*
 * @lc app=leetcode id=11 lang=cpp
 *
 * [11] Container With Most Water
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxNum = 0;

        while (left < right) {
            maxNum =
                max(maxNum, (right - left) * min(height[left], height[right]));

            if (height[left] <= height[right]) {
                ++left;
            } else {
                --right;
            }
        }

        return maxNum;
    }
};
// @lc code=end
