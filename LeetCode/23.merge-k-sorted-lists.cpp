/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 */

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  private:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;

        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val >= list2->val) {
                curr->next = list2;
                list2 = list2->next;
            } else {
                curr->next = list1;
                list1 = list1->next;
            }

            curr = curr->next;
        }

        curr->next = (list1 != nullptr) ? list1 : list2;

        ListNode* mergedList = dummyHead->next;

        delete dummyHead;

        return mergedList;
    }

  public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty() == true) {
            return nullptr;
        }

        while (lists.size() > 1) {
            vector<ListNode*> temp;

            for (int i = 0; i < lists.size(); i += 2) {
                ListNode* list1 = lists[i];
                ListNode* list2 =
                    (i + 1 < lists.size()) ? lists[i + 1] : nullptr;

                temp.push_back(mergeTwoLists(list1, list2));
            }

            lists = move(temp);
        }

        return lists[0];
    }
};
// @lc code=end
