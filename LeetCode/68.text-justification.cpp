/*
 * @lc app=leetcode id=68 lang=cpp
 *
 * [68] Text Justification
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  public:
    // https://leetcode.com/problems/text-justification/solutions/3952119/94-14-2-approaches-greedy/
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int currLen = 0;
        vector<string> currWords, result;

        for (const string& word : words) {
            // 現在累積長度+這個單字長度+目前單字數量(原本是currWords.size()-1，但加上現在要判斷的這個單字，要把1加回去)
            if (currLen + word.length() + currWords.size() > maxWidth) {
                int spaces = maxWidth - currLen;
                int gaps = currWords.size() - 1;

                if (gaps == 0) {  // 只有一個單字
                    result.push_back(currWords[0] + string(spaces, ' '));
                } else {
                    string line;
                    int spacePerGap = spaces / gaps;
                    int extraSpaces = spaces % gaps;

                    for (int i = 0; i < currWords.size(); ++i) {
                        line += currWords[i];

                        if (i < gaps) {
                            line += string(spacePerGap, ' ');

                            if (i < extraSpaces) {
                                line += ' ';
                            }
                        }
                    }

                    result.push_back(line);
                }

                currLen = 0;
                currWords.clear();
            }

            currLen += word.length();
            currWords.push_back(word);
        }

        // 上面未滿一行就會到最後一行
        string lastLine;

        for (const string& word : currWords) {
            if (lastLine.empty() == false) {  // 如果不是第一個單字
                lastLine += ' ';
            }

            lastLine += word;
        }

        lastLine += string(maxWidth - lastLine.length(), ' ');
        result.push_back(lastLine);

        return result;
    }
};
// @lc code=end
