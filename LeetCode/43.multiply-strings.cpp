/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }

        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        int n = num1.size() + num2.size();
        string result(n, '0');

        for (int i = 0; i < num1.size(); ++i) {
            int value1 = num1[i] - '0';

            for (int j = 0; j < num2.size(); ++j) {
                int value2 = num2[j] - '0';
                int carry = result[i + j] - '0';

                int product = value1 * value2 + carry;

                result[i + j] = (product % 10) + '0';
                result[i + j + 1] +=
                    product /
                    10;  // 就算超過9也會在運算到這一位的時候取出來修正
            }
        }

        if (result.back() == '0') {
            result.pop_back();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};
// @lc code=end
