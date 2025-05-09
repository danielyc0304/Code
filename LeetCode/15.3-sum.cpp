/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for (int i = 0; i < nums.size() - 2; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            int j = i + 1, k = nums.size() - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                if (sum == 0) {
                    result.push_back({nums[i], nums[j++], nums[k--]});

                    while (nums[j] == nums[j - 1] && j < k) {
                        ++j;
                    }
                    while (nums[k] == nums[k + 1] && j < k) {
                        --k;
                    }
                } else if (sum > 0) {
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
