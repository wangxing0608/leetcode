/*
 * @lc app=leetcode id=21 lang=cpp
 *
 * [21] Merge Two Sorted Lists
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *prehead = new ListNode(-1);   // 定义合并链表之前的一个头结点
        ListNode *prev = prehead;
        // 两个链表都不为空, 则合并
        while (l1 != nullptr && l2 != nullptr)
        {
            if (l1 -> val <= l2 -> val)
            {
                prev -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                prev -> next = l2;
                l2 = l2 -> next;
            }
            prev = prev -> next;
        }
        // l1和l2链表中有一个已经为空链表
        prev -> next = l1 != nullptr ? l1 : l2;

        return prehead -> next;
    }
};

