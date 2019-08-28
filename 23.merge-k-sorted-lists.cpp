/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
 *
 * https://leetcode.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (35.69%)
 * Likes:    2828
 * Dislikes: 185
 * Total Accepted:    436.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * Output: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 链表组为空
        if (lists.empty())
        {
            return nullptr;
        }
        // 待排序的链表数
        int n = lists.size();
        while (n > 1)
        {
            int k = (n + 1) / 2;       // 待合并的两个链表的距离
            for (int i = 0; i < n / 2; ++i)
            {
                lists[i] = mergeTwoLists(lists[i], lists[i + k]);
            }
            n = k; 
        }
        return lists[0];
    }

    // 合并两个链表的辅助函数
    ListNode * mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode * dummy = new ListNode(-1);      // dummy指向新建链表的头节点
        ListNode *cur = dummy;                    // 新链表待插入元素的位置
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

        // l1不为空
        if (l1)
        {
            cur -> next = l1;
        }

        // l2不为空
        if (l2)
        {
            cur -> next = l2;
        }

        return dummy -> next;
    }

};

