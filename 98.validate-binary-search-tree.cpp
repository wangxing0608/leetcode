/*
 * @lc app=leetcode id=98 lang=cpp
 *
 * [98] Validate Binary Search Tree
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
    bool isValidBST(TreeNode* root) {
        stack<TreeNode *> s;
        TreeNode *p = root;
        TreeNode *pre = nullptr;  
        while (p || !s.empty())
        {
            // 将当前节点压栈
            while (p)
            {
                s.push(p);
                p = p -> left;
            }
            // 栈中弹出保存的当前节点
            p = s.top();
            s.pop();
            // 如果中序遍历中的前一个节点的值大于当前节点的值
            if (pre && p -> val <= pre -> val)
            {
                return false;
            }
            pre = p;
            p = p -> right;
        }
        return true;
    }
};

