/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
 *
 * https://leetcode.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (36.83%)
 * Likes:    1659
 * Dislikes: 86
 * Total Accepted:    201.5K
 * Total Submissions: 546.7K
 * Testcase Example:  '[4,2,1,3]'
 *
 * Sort a linked list in O(n log n) time using constant space complexity.
 * 
 * Example 1:
 * 
 * 
 * Input: 4->2->1->3
 * Output: 1->2->3->4
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: -1->5->3->4->0
 * Output: -1->0->3->4->5
 * 
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
    ListNode* sortList(ListNode* head) {
        // 边界条件
        if (head == nullptr || head -> next == nullptr)
        {
            return head;
        }

        // 使用快慢指针找到链表的中间节点
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *pre = head;
        while (fast && fast -> next)
        {
            pre = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        pre -> next = nullptr;
        return merge(sortList(head), sortList(slow)); 
    }

    ListNode* merge(ListNode *l1, ListNode *l2)
    {
        ListNode *dummy = new ListNode(-1);  // dummy指向合并后的有序链表
        ListNode *cur = dummy;
        // 两个链表都不为空
        while (l1 && l2)
        {
            if (l1 -> val <= l2 -> val)
            {
                cur -> next = l1;
                l1 = l1 -> next;
            }
            else
            {
                cur -> next = l2;
                l2 = l2 -> next;
            }
            cur = cur -> next;
        }

        if (l1)
        {
            cur -> next = l1;
        }
        if (l2)
        {
            cur -> next = l2;
        }
        return dummy -> next;
    }
};

