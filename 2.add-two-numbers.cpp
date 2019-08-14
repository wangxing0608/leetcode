/*
 * @lc app=leetcode id=2 lang=cpp
 *
 * [2] Add Two Numbers
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // 边界条件,判断两个链表中是否有空链表
        if (l1 == nullptr)
        {
            return l2;
        }
        if ( l2 == nullptr)
        {
            return l1;
        }

        // 结果链表的头结点
        ListNode * list3 = nullptr;
        // 结果链表的尾节点
        ListNode * list3Tail = nullptr;
        // 保存计算结果和进位
        int value = 0, carry = 0;
        while (l1 || l2)
        {
            // 求两个链表当前节点的和
            value = carry + (l1 ? l1 -> val : 0) + (l2 ? l2 -> val : 0);
            // 如果需要进位
            if (value > 9)
            {
                carry = 1;
                value = value % 10;
            }
            else 
            {
                carry = 0;
            }

            // 创建保存相加和的节点
            ListNode *temp = new ListNode(value);

            // 该节点为结果链表中的第一个节点
            if (list3 == nullptr)
            {
                list3 = temp;
            }
            else 
            {
                list3Tail -> next = temp;
            }
            // 移动listTail指针到结果链表尾部
            list3Tail = temp;

            // 移动l1和l2链表指针
            if (l1)
            {
                l1 = l1 -> next ; // 链表l1向后移动一个节点
            }
            if (l2) 
            {
                l2 = l2 -> next;  // 链表l2向后移动一个节点
            }
        }

        // 最后一位有进位
        if (carry > 0)
        {
            list3Tail -> next = new ListNode(carry);
        }
        return list3;
    }
};

