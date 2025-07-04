/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int jump(vector<int>& nums) {
        int near = 0, far = 0, jump = 0;

        while (far < nums.size() - 1) {
            int farthest = 0;

            for (int i = near; i <= far; ++i) {
                farthest = max(farthest, i + nums[i]);
            }

            near = far + 1;
            far = farthest;
            ++jump;
        }

        return jump;
    }
};
// @lc code=end
