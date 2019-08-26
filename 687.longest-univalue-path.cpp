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
        int result = 0;
        // 树为空
        if (root == nullptr)
        {
            return 1;
        }

        if ((root -> left) -> val != (root -> right) -> val)
        {
            return result;
        }
        else 
        {
            result +=1;
            return max(longestUnivaluePath(root -> left), longestUnivaluePath(root -> right));
        }
    }
};

