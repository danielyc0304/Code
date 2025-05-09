/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    // https://leetcode.com/problems/substring-with-concatenation-of-all-words/solutions/4967007/c-optimal-solution-clean-code-commented-and-explained/
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> maxSeen;

        for (const string& word : words) {
            ++maxSeen[word];
        }

        int len = words[0].length();
        vector<int> result;

        for (int i = 0; i < len; ++i) {
            unordered_map<string, int> seen;
            int matchSize =
                0;  // 以word的個數來計算，matchSize=1代表有一個word被匹配

            for (int j = i; j < s.length(); j += len) {
                string subStr = s.substr(j, len);
                auto it = maxSeen.find(subStr);

                if (it == maxSeen.end()) {
                    seen.clear();
                    matchSize = 0;

                    continue;
                }

                ++seen[subStr];
                ++matchSize;

                while (seen[subStr] > maxSeen[subStr]) {
                    string firstWord = s.substr(j - (matchSize - 1) * len, len);

                    --seen[firstWord];
                    --matchSize;
                }

                if (matchSize == words.size()) {
                    result.push_back(j - (matchSize - 1) * len);
                }
            }
        }

        return result;
    }
};
// @lc code=end
