/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    void nextPermutation(vector<int>& nums) {
        int i = nums.size() - 2;

        // 找到遞減轉折點
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            --i;
        }

        if (i >= 0) {
            int j = nums.size() - 1;

            // 讓nums[i]的數字增加越少越好(因為要找下一個字典序)
            // 因為右邊都是遞減，所以可以找到跟nums[i]差最少的的比較大的數字
            while (nums[j] <= nums[i]) {
                --j;
            }

            swap(nums[i], nums[j]);  // 交換完之後右邊還會是遞減數列
        }

        reverse(nums.begin() + i + 1, nums.end());  // 右邊變遞增數列

        // 結果：nums[i]的數字增加最少，右邊的數列變遞增數列 -> 下一個字典序
    }
};
// @lc code=end
