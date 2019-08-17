/*
 * @lc app=leetcode id=234 lang=cpp
 *
 * [234] Palindrome Linked List
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
    bool isPalindrome(ListNode* head) {
        // 链表为空或只有一个节点
        if (!head || head -> next == nullptr)
        {
            return true;
        }

        ListNode *slow = head;  // 慢指针
        ListNode *fast = head;  // 快指针

        while (fast -> next && fast -> next -> next)
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        ListNode *last = slow -> next;
        ListNode *pre = head;
        // 将链表的后半部分翻转
        while (last -> next)
        {
            ListNode *tmp = last -> next;
            last -> next = tmp -> next;
            tmp -> next = slow -> next;
            slow -> next = tmp;
        }
        // 比较链表的前半部分及后半部分是否相等
        while (slow -> next)
        {
            slow = slow -> next;
            if (pre -> val != slow -> val)
            {
                return false;
            }
            pre = pre -> next;
        }
        return true;
    }
};

