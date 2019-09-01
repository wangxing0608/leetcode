/*
 * @lc app=leetcode id=206 lang=cpp
 *
 * [206] Reverse Linked List
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
    ListNode* reverseList(ListNode* head) {
        // 边界条件
        if (head == nullptr || head -> next == nullptr)
        {
            return head;
        }

        ListNode *newHead = reverseList(head -> next);
        head -> next -> next = head;  // 将当前节点链接到翻转的链表中
        head -> next = nullptr;       // 从顺序链表中断开当前节点
        return newHead;               
    }
};

