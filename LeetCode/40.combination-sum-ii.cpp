/*
 * @lc app=leetcode id=40 lang=cpp
 *
 * [40] Combination Sum II
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    void backtrack(const vector<int>& candidates, int start, int left,
                   vector<int>& com, vector<vector<int>>& result) {
        if (left == 0) {
            result.push_back(com);

            return;
        }

        if (left < 0 || start == candidates.size()) {
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            // 在同一層中的同一個元素會被跳過，但在不同層中還是會出現，所以可以避免重複的組合，但又可以試到重複的數字
            // 條件式：如果不是第一個元素，且已經重複了
            if (i > start && candidates[i] == candidates[i - 1]) {
                continue;
            }

            com.push_back(candidates[i]);
            backtrack(candidates, i + 1, left - candidates[i], com, result);
            com.pop_back();
        }
    }

  public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());

        vector<int> com;
        vector<vector<int>> result;

        backtrack(candidates, 0, target, com, result);

        return result;
    }
};
// @lc code=end
