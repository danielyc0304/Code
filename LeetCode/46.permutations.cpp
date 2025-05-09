/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    void backtrack(vector<int>& nums, int start, vector<vector<int>>& result) {
        if (start == nums.size() - 1) {
            result.push_back(nums);

            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            swap(nums[start], nums[i]);

            backtrack(nums, start + 1, result);

            swap(nums[start], nums[i]);
        }
    }

  public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;

        backtrack(nums, 0, result);

        return result;
    }
};
// @lc code=end
