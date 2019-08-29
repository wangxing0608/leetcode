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

        // 边界条件，如果两个链表其中一个为空    
        if (headA == nullptr || headB == nullptr)
        {
            return nullptr;
        }

        // 获得两个链表的长度
        int len1 = getListLen(headA);
        int len2 = getListLen(headB);

        // 求两个链表的长度差，将较长链表向前移动相应的步长     
        if (len1 >= len2)
        {
            for (int i = 0; i < len1 - len2; ++i)
            {
                headA = headA -> next;
            }
        }
        else  
        {
            for (int i = 0; i < len2 - len1; ++i)
            {
                headB = headB -> next;
            }
        }

        // 寻找两个链表的相交点
        while (headA != nullptr && headB != nullptr && headA != headB)
        {
            headA = headA -> next;
            headB = headB -> next;
        }

        // 两个链表相交，则返回相应的节点，不想交返回nullptr
        return (headA != nullptr && headB != nullptr) ? headA :nullptr;
        
    }

    // 获得链表长度的辅助函数
    int getListLen(ListNode *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            head = head -> next;
            len++;
        }

        return len;
    }
};

