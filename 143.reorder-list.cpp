/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
 *
 * https://leetcode.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (31.85%)
 * Likes:    1039
 * Dislikes: 76
 * Total Accepted:    166.4K
 * Total Submissions: 522.2K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a singly linked list L: L0→L1→…→Ln-1→Ln,
 * reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * Example 1:
 * 
 * 
 * Given 1->2->3->4, reorder it to 1->4->2->3.
 * 
 * Example 2:
 * 
 * 
 * Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
 * 
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
    void reorderList(ListNode* head) {
        if (!head || !head -> next || !head -> next -> next)
        {
            return;
        }

        // 创建快慢指针
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast -> next && fast -> next -> next )
        {
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *mid = slow -> next;  //  链表后半部分的开始
        slow -> next =  nullptr;  // 断开链表的前半部分和后半部分
        ListNode *last = mid;     // 反转后指向链表的最后一个节点
        ListNode *pre = nullptr;  // 反转后指向链表的第一个节点
        
        // 将链表的后半部分反转
        while (last)
        {
            ListNode *next = last -> next;  // next指向当前节点的下一个节点
            last -> next = pre;    // 反转链表
            pre = last;            // 反转链表 
            last = next;           // last 移动到下一个需要反转的节点 
        }
        
        // 将链表前半部分和反转后的后半部分进行重排序
        while (head && pre)
        {
            ListNode *next = head -> next;
            head -> next = pre;
            pre = pre -> next;
            head -> next -> next = next;
            head = next;
        }
    }
};

