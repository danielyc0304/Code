/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */

#include <iostream>
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
  public:
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

        ListNode* result = dummyHead->next;

        delete dummyHead;

        return result;
    }
};
// @lc code=end
