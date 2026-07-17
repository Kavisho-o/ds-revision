# Binary Tree Maximum Path Sum

- tc: **O(n)**
- sc: **O(h)** recursion stack (**O(n)** worst case)

## pattern
- tree dp
- postorder dfs
- recursive tree traversal
- compute subtree gain
- update global answer
- ignore negative paths

## blackbox

```cpp
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
```

## intuition

- Perform a **postorder DFS** so the left and right subtree gains are known before processing the current node.
- Ignore negative subtree gains since they only decrease the path sum.
- At each node, compute the best path **passing through that node**:
  - `root + leftGain + rightGain`
- Update the global maximum with this value.
- Return only one branch upward:
  - `root + max(leftGain, rightGain)`
- A parent can continue a path through **only one child**, so both branches cannot be returned.

## memory trick

- **Ignore negative gains.**
- **Update answer with both branches.**
- **Return only one branch upward.**