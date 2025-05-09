/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.length(); ++right) {
            char c = s[right];

            // 第二個條件式：如果上次看到是在window外就不理他
            if (lastSeen.find(c) != lastSeen.end() && lastSeen[c] >= left) {
                left = lastSeen[c] + 1;
            }

            lastSeen[c] = right;
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};
// @lc code=end
