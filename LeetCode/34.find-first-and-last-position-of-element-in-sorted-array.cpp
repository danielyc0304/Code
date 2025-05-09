/*
 * @lc app=leetcode id=34 lang=cpp
 *
 * [34] Find First and Last Position of Element in Sorted Array
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    int binarySearch(const vector<int>& nums, int target, bool findFirst) {
        int left = 0, right = nums.size() - 1;
        int i = -1;

        while (left <= right) {
            int middle = (left + right) / 2;

            if (nums[middle] == target) {
                i = middle;

                if (findFirst == true) {  // 往左邊找
                    right = middle - 1;
                } else {  // 往右邊找
                    left = middle + 1;
                }
            } else if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }

        return i;
    }

  public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};

        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);

        result = {left, right};

        return result;
    }
};
// @lc code=end
