/*
 * @lc app=leetcode id=26 lang=cpp
 *
 * [26] Remove Duplicates from Sorted Array
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    int removeDuplicates(vector<int>& nums) {
        int j = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                nums[j++] = nums[i];
            }
        }

        return j;
    }
};
// @lc code=end
