/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    // https://leetcode.com/problems/permutation-sequence/solutions/696595/c-very-easy-and-detailed-explanation-idea-code/
    string getPermutation(int n, int k) {
        vector<int> nums;
        int numberEachGroup = 1;

        for (int i = 1; i < n; ++i) {
            nums.push_back(i);
            numberEachGroup *= i;
        }
        nums.push_back(n);

        string result = "";

        --k;  // 換成0-indexed
        while (nums.size() > 0) {
            result += to_string(nums[k / numberEachGroup]);
            nums.erase(nums.begin() + k / numberEachGroup);

            if (nums.size() == 0) {
                break;
            }

            k %= numberEachGroup;
            numberEachGroup /= nums.size();
        }

        return result;
    }
};
// @lc code=end
