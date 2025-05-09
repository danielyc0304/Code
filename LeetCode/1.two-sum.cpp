/*
 * @lc app=leetcode id=1 lang=cpp
 *
 * [1] Two Sum
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash;  // <數字,數字的位置>

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            // 從i往前找看有沒有已儲存的數字=complement
            if (hash.find(complement) != hash.end()) {
                return {hash[complement], i};
            }

            hash[nums[i]] = i;
        }

        return {};
    }
};
// @lc code=end
