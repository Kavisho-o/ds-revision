/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {

        if (!root) return ;
        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty()){
            
            TreeNode* curr=st.top(); st.pop();

            // since its a stack the right will get processed first 
            if (curr->right) st.push(curr->right);
            if (curr->left) st.push(curr->left);

            if (!st.empty()) curr->right=st.top();
            curr->left=nullptr;
        }

    }
        
};
// @lc code=end

