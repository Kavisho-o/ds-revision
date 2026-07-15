/*
 * @lc app=leetcode id=236 lang=cpp
 *
 * [236] Lowest Common Ancestor of a Binary Tree
 */

// @lc code=start
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (!root) return nullptr;

        if (root==p || root==q) return root; // either found -> keep it

        TreeNode *l=lowestCommonAncestor(root->left,p,q);
        TreeNode *r=lowestCommonAncestor(root->right,p,q);

        if (l&&r) return root;               // both found -> root is lca
        return l?l:r;                        // if left is null -> answer is in right subtree
                                             // if right is null -> answer is in left subtree
        
    }
};
// @lc code=end

