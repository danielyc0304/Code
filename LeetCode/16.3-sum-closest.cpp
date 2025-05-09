/*
 * @lc app=leetcode id=16 lang=cpp
 *
 * [16] 3Sum Closest
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        int result = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (abs(sum - target) < abs(result - target)) {
                    result = sum;
                }

                if (sum == target) {
                    return sum;
                } else if (sum > target) {
                    --k;

                    /* 不加比較快
                    while (nums[k] == nums[k + 1] && j < k) {
                        --k;
                    }
                    */
                } else {
                    ++j;

                    /* 不加比較快
                    while (nums[j] == nums[j - 1] && j < k) {
                        ++j;
                    }
                    */
                }
            }
        }

        return result;
    }
};
// @lc code=end
