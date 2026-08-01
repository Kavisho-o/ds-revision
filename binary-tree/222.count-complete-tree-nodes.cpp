/*
 * @lc app=leetcode id=222 lang=cpp
 *
 * [222] Count Complete Tree Nodes
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
    int countNodes(TreeNode* root) {

        if (!root) return 0;

        TreeNode *l=root, *r=root;
        int ln=0,rn=0;

        while (l) { ln++; l=l->left; }
        while (r) { rn++; r=r->right; } 

        if (l==r) return (1<<ln)-1; // 2^h-1
        return 1+ countNodes(root->left) + countNodes(root->right);   // in a perfect bt, atleast one of 
                                                                      // the two subtrees is a perfect bt   
        
    }
};
// @lc code=end

