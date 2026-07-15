/*
 * @lc app=leetcode id=543 lang=cpp
 *
 * [543] Diameter of Binary Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {

        return diameter(root);
        
    }

     int diameter(TreeNode* root){

        if (!root) return 0;

        int lsubtreeH=height(root->left);
        int rsubtreeH=height(root->right);
        int lrootr=lsubtreeH+rsubtreeH;

        int ldia=diameter(root->left);
        int rdia=diameter(root->right);
        return max({lrootr,ldia,rdia});

    }
};
// @lc code=end

