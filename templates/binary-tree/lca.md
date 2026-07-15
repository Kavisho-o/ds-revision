## Lowest Common Ancestor (LCA)
- tc: O(n)
- sc: O(h) (O(n) in worst case)

## pattern
- lowest common ancestor
- postorder dfs
- recursive tree traversal
- return found node upward
- split point is the lca

## blackbox
```cpp
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

    if (!root) return nullptr;

    if (root==p || root==q) return root; // either found -> keep it

    TreeNode *l=lowestCommonAncestor(root->left,p,q);
    TreeNode *r=lowestCommonAncestor(root->right,p,q);

    if (l&&r) return root;               // both found -> root is lca
    return l?l:r;                        // if left is null -> answer is in right subtree
                                         // if right is null -> answer is in left subtree
    
}
```