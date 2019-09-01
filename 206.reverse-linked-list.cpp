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
        ListNode *newHead = nullptr;   // 翻转后的链表的头结点
        // 顺序遍历链表
        while (head)
        {
            ListNode *temp = head -> next; // 指向待翻转节点的后一个节点
            head -> next = newHead;        // 当前节点链接到翻转链表
            newHead = head;                // 头节点向后移动
            head = temp;                   // 带翻转节点向后移动
        }
        return newHead;
    }
};

