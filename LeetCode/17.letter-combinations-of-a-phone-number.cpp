/*
 * @lc app=leetcode id=17 lang=cpp
 *
 * [17] Letter Combinations of a Phone Number
 */

#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  private:
    void backtrack(const string& digits,
                   const unordered_map<char, string>& digitToLetters, int index,
                   string current, vector<string>& result) {
        if (index == digits.length()) {
            result.push_back(current);

            return;
        }

        string letters = digitToLetters.at(digits[index]);
        for (char letter : letters) {
            backtrack(digits, digitToLetters, index + 1, current + letter,
                      result);
        }
    }

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty() == true) {
            return {};
        }

        unordered_map<char, string> digitToLetters = {
            {'2', "abc"}, {'3', "def"},  {'4', "ghi"}, {'5', "jkl"},
            {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

        vector<string> result;

        backtrack(digits, digitToLetters, 0, "", result);

        return result;
    }
};
// @lc code=end
