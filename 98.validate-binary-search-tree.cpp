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
        return helper(root, LONG_MIN, LONG_MAX);
    }

    bool helper(TreeNode *root, long mn, long mx)
    {
        if (root == nullptr)
        {
            return true;      // 以root 为根的树为空
        }
        // 左右子树中的值必须满足一定的范围
        if (root -> val <= mn || root -> val >= mx)
        {
            return false;
        }

        // 递归调用左右子树
        // 左子树中的值小于根节点的值
        // 右子树中的值大于根节点的值    
        return helper(root -> left, mn, root -> val) && helper(root -> right, root -> val, mx);
    }
};

