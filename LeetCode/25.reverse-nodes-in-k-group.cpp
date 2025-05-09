/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 */

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
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
    int length(ListNode* head) {
        int len = 0;

        while (head != nullptr) {
            ++len;
            head = head->next;
        }

        return len;
    }

  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);

        if (len < k) {
            return head;
        }

        ListNode* dummyHead = new ListNode(0);
        ListNode* groupedHead = dummyHead;  // groupedHead會維持在一組的最前面
        ListNode *curr = head, *nex = head->next;

        for (int i = 0; i < len / k; ++i) {
            for (int j = 0; j < k; ++j) {
                // 每次都把元素插入在一組的最前面
                curr->next = groupedHead->next;
                groupedHead->next = curr;
                curr = nex;

                if (nex != nullptr) {
                    nex = nex->next;
                }
            }

            // 移到下一組的開頭
            while (groupedHead->next != nullptr) {
                groupedHead = groupedHead->next;
            }
        }

        // 未滿一組的元素
        while (curr != nullptr) {
            groupedHead->next = curr;
            groupedHead = groupedHead->next;
            curr = curr->next;
        }

        ListNode* result = dummyHead->next;

        delete dummyHead;

        return result;
    }
};
// @lc code=end
