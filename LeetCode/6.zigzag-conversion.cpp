/*
 * @lc app=leetcode id=6 lang=cpp
 *
 * [6] Zigzag Conversion
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    string convert(string s, int numRows) {
        size_t n = s.length();

        if (numRows == 1 || numRows >= n) {
            return s;
        }

        char result[n + 1];
        int k = 0;

        for (int i = 0; i < numRows; ++i) {
            for (int j = i; j < n; j += 2 * (numRows - 1)) {
                result[k++] = s[j];

                if (i > 0 && i < numRows - 1 &&
                    j + 2 * (numRows - 1) - 2 * i < n) {
                    result[k++] = s[j + 2 * (numRows - 1) - 2 * i];
                }
            }
        }

        result[k] = '\0';

        return result;
    }
};
// @lc code=end
