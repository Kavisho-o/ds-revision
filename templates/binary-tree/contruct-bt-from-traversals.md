# Construct Binary Tree from Preorder + Inorder

- tc: **O(n)**
- sc: **O(h)** recursion stack (**O(n)** worst case) + **O(n)** hashmap

## pattern
- construct binary tree
- preorder + inorder
- recursive divide and conquer
- preorder gives current root
- inorder splits left/right subtree

## blackbox

```cpp
TreeNode* help(vector<int>& preorder, unordered_map<int,int>& mp,
               int s, int e, int& idx) {

    if (s > e) return nullptr;

    int rootVal = preorder[idx++];          // preorder -> root first
    TreeNode* root = new TreeNode(rootVal);

    int mid = mp[rootVal];                  // locate root in inorder

    root->left = help(preorder, mp, s, mid - 1, idx);
    root->right = help(preorder, mp, mid + 1, e, idx);

    return root;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

    unordered_map<int,int> mp;
    for (int i = 0; i < inorder.size(); i++) mp[inorder[i]] = i;

    int idx = 0;
    return help(preorder, mp, 0, inorder.size() - 1, idx);
}
```

## intuition

- **Preorder** (`Root → Left → Right`) always visits the **root first**.
- Pick the next root from preorder using `idx`.
- Find the root's position in **inorder** using the hashmap.
- Everything left of the root in inorder belongs to the **left subtree**.
- Everything right of the root belongs to the **right subtree**.
- Recursively build the left subtree first, then the right subtree.
- Stop when the current inorder range becomes empty (`s > e`).

## memory trick

- **Preorder gives the Root.**
- **Inorder splits the Tree.**
- **Build Left → Build Right.**