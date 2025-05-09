/*
 * @lc app=leetcode id=5 lang=cpp
 *
 * [5] Longest Palindromic Substring
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    // https://leetcode.com/problems/longest-palindromic-substring/solutions/3598120/longest-palindromic-substring/?source=vscode
    // approach 4
    string longestPalindrome(string s) {
        string sPrime = "#";

        for (char c : s) {
            sPrime += string(1, c) + "#";
        }

        int n = sPrime.length();
        int center = 0, radius = 0;
        vector<int> radii(n, 0);

        for (int i = 0; i < n; ++i) {
            int mirror = 2 * center - i;  // i對稱於center的點

            if (i < radius) {
                radii[i] = min(
                    radius - i,
                    radii
                        [mirror]);  // i+radii[mirror]有可能超過radius，這時只能使用radius-i當作最大安全範圍
            }

            while (i - radii[i] - 1 >= 0 && i + radii[i] + 1 < n &&
                   sPrime[i - radii[i] - 1] == sPrime[i + radii[i] + 1]) {
                ++radii[i];
            }

            // 如果掃的範圍已經超過radius，就更新成目前掃最遠的範圍
            if (i + radii[i] > radius) {
                center = i;
                radius = i + radii[i];
            }
        }

        // 因為上面找的資料是目前的資料，所以要重頭再找一次
        center = 0, radius = 0;
        for (int i = 0; i < n; ++i) {
            if (radii[i] > radius) {
                center = i;
                radius = radii[i];
            }
        }

        int start = (center - radius) / 2;

        return s.substr(
            start, radius);  // radius不用除以2，因為半徑轉換出來剛好是完整長度
    }
};
// @lc code=end
