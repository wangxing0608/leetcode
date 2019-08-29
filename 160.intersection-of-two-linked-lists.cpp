/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        // 边界条件，两个链表中有一个为空
        if (! headA || !headB)
        {
            return nullptr;
        }

        ListNode *a = headA;
        ListNode *b = headB;
        
        // 两个节点相等的条件有2:
        // 1. 节点a和节点b各自遍历两个链表的长度后到达末尾的空节点
        // 2. 节点a遍历完链表headA后进入链表listB中向前进到达链表的交点
        // 如果相交，节点a和节点b到达交点走过的长度一定相等
        while (a != b)
        {
            a = a ? a -> next : headB;
            b = b ? b -> next : headA;
        }
        return a;
    }
};

