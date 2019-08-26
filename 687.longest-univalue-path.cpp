/*
 * @lc app=leetcode id=687 lang=cpp
 *
 * [687] Longest Univalue Path
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
    int longestUnivaluePath(TreeNode* root) {
        int result = 0;  // 保存最长相同值路径结果
        helper(root, result);   // 递归调用的辅助函数
        return result;
    }

    // 传递result的引用,使其能够保存递归调用结果
    int helper(TreeNode *node, int &result)
    {
        // 当前节点为空
        if (node == nullptr)
        {
            return 0;
        }

        // 递归求左子树中最长相同值路径长度
        int left = helper(node -> left, result);
        // 递归求右子树中最长相同值路径长度
        int right = helper(node -> right, result);
        // 左子树不为空,且与当前节点值相同
        left = (node -> left && node -> val == node -> left -> val) ? left + 1 : 0;
        // 右子树不为空,且与当前节点值相同 
        right = (node -> right && node -> val == node -> right -> val) ? right + 1 : 0;
        result = max(result, left + right);
        return max(left, right);
    }
};

