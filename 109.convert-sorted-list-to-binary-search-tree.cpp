/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 *
 * https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (41.95%)
 * Likes:    1152
 * Dislikes: 71
 * Total Accepted:    187.2K
 * Total Submissions: 446.1K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * Given a singly linked list where elements are sorted in ascending order,
 * convert it to a height balanced BST.
 * 
 * For this problem, a height-balanced binary tree is defined as a binary tree
 * in which the depth of the two subtrees of every node never differ by more
 * than 1.
 * 
 * Example:
 * 
 * 
 * Given the sorted linked list: [-10,-3,0,5,9],
 * 
 * One possible answer is: [0,-3,9,-10,null,5], which represents the following
 * height balanced BST:
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        // 链表为空
        if (!head)
        {
            return nullptr;
        }
        // 链表只有一个节点
        if (head -> next == nullptr)
        {
            return new TreeNode( head -> val);
        }

        ListNode *slow = head;  // 慢指针
        ListNode *fast = head;  // 快指针
        ListNode *last = slow;  //指向左子树的最后一个节点
        // slow指针找到链表的中间节点
        while (fast -> next && fast -> next -> next)
        {
            last = slow;
            slow = slow -> next;
            fast = fast -> next -> next;
        }
        fast = slow -> next;     // fast 指针指向右子树的开始
        last -> next = nullptr;  // last -> next 重置为nullptr
        TreeNode *cur = new TreeNode(slow -> val); // 创建二叉树根节点
        // 当前节点的左子树中有节点
        if (head != slow)
        {
            cur -> left = sortedListToBST(head);  // 递归遍历左子树
        }
        cur -> right = sortedListToBST(fast);     // 递归遍历右子树
        return cur;
    }
};

