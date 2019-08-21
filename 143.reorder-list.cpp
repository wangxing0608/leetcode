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
        // 链表为空或链表只含一个节点或链表只含两个节点
        if (!head || !head -> next || !head -> next -> next)
        {
            return;
        }

        // 将链表后半部分反转的栈
        stack<ListNode *> stack;
        ListNode * cur = head;
        while (cur)
        {
            stack.push(cur);
            cur = cur -> next;
        }

        int cnt = ((int)stack.size() -1) / 2;
        cur = head;
        while (cnt-- > 0)
        {
            auto tmp = stack.top();  // 保存存栈中弹出的节点
            stack.pop();
            ListNode *next = cur -> next;  // next指针保存现在顺序下cur后继节点
            cur -> next = tmp;             // 将栈中弹出节点链接到cur节点后
            tmp -> next = next;            // next节点连接到栈中弹出节点后 
            cur = next;                    // cur指针指向next节点
        }
        stack.top() -> next = nullptr;     // 栈中最后一个节点的后继节点设为nullptr,防止重排后链表出现环 
    }
};

