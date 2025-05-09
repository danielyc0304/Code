/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> grouped;

        for (const string& str : strs) {
            string sortedStr = str;

            sort(sortedStr.begin(), sortedStr.end());

            grouped[sortedStr].push_back(str);
        }

        vector<vector<string>> result;

        for (const auto& [_, vec] : grouped) {
            result.push_back(vec);
        }

        return result;
    }
};
// @lc code=end
