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
        // 链表为空或链表只有一个元素
        if (head == nullptr || head -> next == nullptr)
        {
            return true;
        }
        ListNode *fast = head;
        ListNode *slow = head;

        // 使用栈保存链表中一半的节点
        std::stack<ListNode *> nodeStack;

        while (slow && fast && fast -> next)
        {
            fast = fast -> next -> next;
            nodeStack.push(slow);
            slow = slow -> next;
        }

        // 链表节点数为奇数
        if (fast && fast -> next == nullptr)
        {
            slow = slow -> next;
        }

        // 通过出栈操作比较链表和它的逆链表
        while (!nodeStack.empty() && slow)
        {
            ListNode *curr = nodeStack.top();
            nodeStack.pop();
            if (curr -> val != slow -> val)
            {
                return false;
            }
            slow = slow -> next;
        }

        return true;
    }
};

