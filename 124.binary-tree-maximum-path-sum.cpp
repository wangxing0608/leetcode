/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        helper(root, result);
        return result;
    }

    int helper(TreeNode *node, int &res)
    {
        // 如果节点为空
        if (node == nullptr)
        {
            return 0;
        }

        // 求左子树的最大路径和
        int left = max(helper(node -> left, res), 0);    // 求当前节点的左子树的最大路径和，因为有的节点可以为负值，需要与0比较
        // 求右子树的最大路径和 
        int right = max(helper(node -> right, res), 0);  // 求当前节点的右子树的最大路径和，因为有的节点可以为负值，需要与0比较
        res = max(res, left + right + node -> val);      // 当前节点的最大路径和等于左右子树中的最大路径和加当前节点值
        return max(left, right) + node -> val;           // 组成路径时只能选择当前节点左右子树中最大路径和的较大者
    }
};

