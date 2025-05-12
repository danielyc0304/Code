/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int result = nums[0];

        for (int num : nums) {
            sum = (sum >= 0) ? sum : 0;
            sum += num;

            result = max(result, sum);
        }

        return result;
    }
};
// @lc code=end
