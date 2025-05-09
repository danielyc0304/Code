/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    void backtrack(unordered_map<int, int>& c, vector<int>& com, int n,
                   vector<vector<int>>& result) {
        if (com.size() == n) {
            result.push_back(com);

            return;
        }

        for (const auto& [num, count] : c) {
            if (count == 0) {
                continue;
            }

            com.push_back(num);
            --c[num];

            backtrack(c, com, n, result);

            com.pop_back();
            ++c[num];
        }
    }

  public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        unordered_map<int, int> c;

        for (int num : nums) {
            c[num]++;
        }

        vector<int> com;
        vector<vector<int>> result;

        backtrack(c, com, nums.size(), result);

        return result;
    }
};
// @lc code=end
