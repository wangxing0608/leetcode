/*
 * @lc app=leetcode id=94 lang=cpp
 *
 * [94] Binary Tree Inorder Traversal
 *
 * https://leetcode.com/problems/binary-tree-inorder-traversal/description/
 *
 * algorithms
 * Medium (57.90%)
 * Likes:    1835
 * Dislikes: 78
 * Total Accepted:    505.7K
 * Total Submissions: 873.5K
 * Testcase Example:  '[1,null,2,3]'
 *
 * Given a binary tree, return the inorder traversal of its nodes' values.
 * 
 * Example:
 * 
 * 
 * Input: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 * 
 * Output: [1,3,2]
 * 
 * Follow up: Recursive solution is trivial, could you do it iteratively?
 * 
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;       // 保存中序遍历结果
        stack<TreeNode *> stack;  // 中序遍历中使用栈保存当前未使用的节点
        
        // 栈非空或树非空
        while (!stack.empty() || root != nullptr)
        {
            if (root != nullptr)
            {
                stack.push(root);      // 在栈中保存当前根节点
                root  = root -> left;  // 向左子树移动
            }
            else 
            {
                // 左子树为空,遍历当前根节点,并转向遍历右子树
                root = stack.top();
                stack.pop();
                result.push_back(root -> val);
                root = root -> right;
            }
        }
        return result;
    }
};

