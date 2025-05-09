/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
  public:
    bool isValid(string s) {
        unordered_map<char, char> mapping = {
            {')', '('}, {'}', '{'}, {']', '['}};
        stack<char> st;

        for (char c : s) {
            if (mapping.find(c) == mapping.end()) {  // 上括號
                st.push(c);
            } else if (st.empty() == false &&
                       st.top() == mapping[c]) {  // 下括號
                st.pop();
            } else {
                return false;
            }
        }

        return st.empty();
    }
};
// @lc code=end
