/*
 * @lc app=leetcode id=39 lang=cpp
 *
 * [39] Combination Sum
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    void backtrack(const vector<int>& candidates, int idx, int left,
                   vector<int>& com, vector<vector<int>>& result) {
        if (left == 0) {
            result.push_back(com);

            return;
        }

        if (left < 0 || idx == candidates.size()) {
            return;
        }

        // 選candidates[idx]
        com.push_back(candidates[idx]);
        backtrack(candidates, idx, left - candidates[idx], com, result);

        // 不選candidates[idx]
        com.pop_back();
        backtrack(candidates, idx + 1, left, com, result);
    }

  public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> com;
        vector<vector<int>> result;

        backtrack(candidates, 0, target, com, result);

        return result;
    }
};
// @lc code=end
