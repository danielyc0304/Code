/*
 * @lc app=leetcode id=38 lang=cpp
 *
 * [38] Count and Say
 */

#include <iostream>
using namespace std;

// @lc code=start
class Solution {
  public:
    string countAndSay(int n) {
        string result = "1";

        for (int i = 1; i < n; ++i) {
            string tmp = "";
            int c = 1;

            for (int j = 1; j < result.length(); ++j) {
                if (result[j] == result[j - 1]) {
                    ++c;
                } else {
                    tmp += to_string(c) + result[j - 1];
                    c = 1;
                }
            }

            tmp += to_string(c) + result.back();
            result = tmp;
        }

        return result;
    }
};
// @lc code=end
