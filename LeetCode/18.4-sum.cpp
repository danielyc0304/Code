/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    vector<vector<int>> twoSum(const vector<int>& nums, int start,
                               long target) {
        int j = start, k = nums.size() - 1;
        vector<vector<int>> result;

        while (j < k) {
            int sum = nums[j] + nums[k];

            if (sum == target) {
                result.push_back({nums[j++], nums[k--]});

                while (nums[j] == nums[j - 1] && j < k) {
                    ++j;
                }
                while (nums[k] == nums[k + 1] && j < k) {
                    --k;
                }
            } else if (sum > target) {
                --k;

                while (nums[k] == nums[k + 1] && j < k) {
                    --k;
                }
            } else {
                ++j;

                while (nums[j] == nums[j - 1] && j < k) {
                    ++j;
                }
            }
        }

        return result;
    }

    vector<vector<int>> kSum(const vector<int>& nums, int start, long target,
                             int k) {
        vector<vector<int>> result;

        if (start == nums.size()) {
            return result;
        }

        long avg = target / k;

        // 如果第一個元素就大於平均值，或最後一個元素小於平均值
        if (avg < nums[start] || avg > nums.back()) {
            return result;
        }

        if (k == 2) {
            return twoSum(nums, start, target);
        }

        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) {
                continue;
            }

            for (const vector<int>& subset :
                 kSum(nums, i + 1, (long)target - nums[i], k - 1)) {
                result.push_back({nums[i]});  // 先加進nums[i]
                result.back().insert(result.back().end(), subset.begin(),
                                     subset.end());  // 再加進找到符合條件的值
            }
        }

        return result;
    }

  public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        return kSum(nums, 0, target, 4);
    }
};
// @lc code=end
