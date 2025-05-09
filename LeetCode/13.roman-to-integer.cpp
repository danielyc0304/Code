/*
 * @lc app=leetcode id=13 lang=cpp
 *
 * [13] Roman to Integer
 */

#include <iostream>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
  private:
    int charToInt(char c) {
        switch (c) {
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
            default:
                return 0;
        }
    }

  public:
    int romanToInt(string s) {
        int n = s.length();
        int result = 0;

        for (int i = 0; i < n - 1; ++i) {
            if (charToInt(s[i]) < charToInt(s[i + 1])) {
                result -= charToInt(s[i]);
            } else {
                result += charToInt(s[i]);
            }
        }

        result += charToInt(s[n - 1]);

        return result;
    }
};
// @lc code=end
