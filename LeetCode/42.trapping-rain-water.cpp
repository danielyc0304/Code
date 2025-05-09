/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    // https://leetcode.com/problems/trapping-rain-water/solutions/5126477/video-keep-max-height-on-the-both-side/
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int maxLeft = height[left], maxRight = height[right];
        int water = 0;

        // 藉由移動小的maxLeft和maxRight，維持高的那個邊界，來保證水不會從另外一邊流出，可以安心算max-height
        while (left < right) {
            if (maxLeft <= maxRight) {
                ++left;
                maxLeft = max(maxLeft, height[left]);
                water += maxLeft - height[left];
            } else {
                --right;
                maxRight = max(maxRight, height[right]);
                water += maxRight - height[right];
            }
        }

        return water;
    }
};
// @lc code=end
