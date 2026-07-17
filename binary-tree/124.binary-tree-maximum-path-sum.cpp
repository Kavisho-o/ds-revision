/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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

    int mx;

    int dfs(TreeNode* root){

        if (!root) return 0;

        // first we gotta ignore negative gains
        int l=max(0,dfs(root->left));
        int r=max(0,dfs(root->right));

        // update global variable (max gain for current path)
        mx=max(mx,root->val+l+r);

        // for keeping a path through this root, the max gain that can be provided is
        // the current val plus the max value its left or right subtree can provide
        return root->val+max(l,r);
        
    }

    int maxPathSum(TreeNode* root) {

        mx=INT_MIN;
        int x=dfs(root); 
        return mx;
        
    }
};
// @lc code=end

