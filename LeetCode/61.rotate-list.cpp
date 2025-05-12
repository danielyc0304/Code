/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(), next(nullptr) {}
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode* tail = head;
        int len = 1;
        while (tail->next) {
            ++len;
            tail = tail->next;
        }

        k = k % len;
        if (k == 0) {
            return head;
        }

        ListNode* curr = head;
        for (int i = 1; i < len - k; ++i) {
            curr = curr->next;
        }

        ListNode* newHead = curr->next;
        curr->next = nullptr;
        tail->next = head;

        return newHead;
    }
};
// @lc code=end
