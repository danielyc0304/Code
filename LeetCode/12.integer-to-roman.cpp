/*
 * @lc app=leetcode id=12 lang=cpp
 *
 * [12] Integer to Roman
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    string intToRoman(int num) {
        vector<pair<int, string>> numToRoman{
            {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
            {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
            {5, "V"},    {4, "IV"},   {1, "I"}};

        string result;

        for (const auto& [value, roman] : numToRoman) {
            if (num == 0) {
                break;
            }

            while (num >= value) {
                result += roman;
                num -= value;
            }
        }

        return result;
    }
};
// @lc code=end
