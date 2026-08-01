/*
 * @lc app=leetcode id=297 lang=cpp
 *
 * [297] Serialize and Deserialize Binary Tree
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
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {

        if (!root) return "null,";
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);
        
    }

    TreeNode* build(stringstream &ss){

        string token;
        getline(ss,token,',');

        if (token=="null") return nullptr;

        TreeNode* root=new TreeNode(stoi(token));
        root->left=build(ss);
        root->right=build(ss);

        return root;

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {

        if (data.empty()) return nullptr;

        stringstream ss(data);
        return build(ss);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

