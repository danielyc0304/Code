/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool canJump(vector<int>& nums) {
        int goal = nums.size() - 1;

        for (int i = goal - 1; i >= 0; --i) {
            if (i + nums[i] >= goal) {
                goal = i;
            }
        }

        return (goal == 0);
    }
};
// @lc code=end
