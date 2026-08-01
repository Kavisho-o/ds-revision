# All Nodes Distance K in Binary Tree

- tc:
  - **O(n)** to build parent mapping
  - **O(n)** for BFS from target
  - **Overall: O(n)**
- sc:
  - **O(n)** parent map
  - **O(n)** visited map
  - **O(n)** queue
  - **Overall: O(n)**

## pattern

- tree to graph conversion
- bfs
- parent mapping
- level order traversal
- multi-directional traversal
- graph bfs on tree

## blackbox

```cpp
class Solution {
public:

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*, TreeNode*> parent;

        // Build parent mapping
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            TreeNode* node = q.front();
            q.pop();

            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }

            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        unordered_set<TreeNode*> vis;

        q.push(target);
        vis.insert(target);

        while (k-- && !q.empty()) {

            int sz = q.size();

            while (sz--) {

                TreeNode* node = q.front();
                q.pop();

                if (node->left && !vis.count(node->left)) {
                    vis.insert(node->left);
                    q.push(node->left);
                }

                if (node->right && !vis.count(node->right)) {
                    vis.insert(node->right);
                    q.push(node->right);
                }

                if (parent.count(node) && !vis.count(parent[node])) {
                    vis.insert(parent[node]);
                    q.push(parent[node]);
                }
            }
        }

        vector<int> ans;

        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;
    }
};
```

## intuition

- A binary tree only lets us move **downwards**.
- Since we also need to move **towards the parent**, first build a **child → parent mapping** using BFS.
- After adding parent pointers, every node effectively has at most **3 neighbors**:
  - left child
  - right child
  - parent
- Now the problem becomes:
  - **Find all graph nodes exactly `k` edges away from the target.**
- Perform a BFS starting from the target.
- Each BFS level represents one unit of distance.
- After processing exactly `k` levels, every node remaining in the queue is at distance `k`.
- Use a visited set to avoid revisiting nodes (especially because parent edges create cycles).

## memory trick

- **Build parent pointers first.**
- **Treat the tree as an undirected graph.**
- **BFS from target for exactly `k` levels.**
- **Remaining queue = answer.**