## Vertical Order Traversal
- tc: O(n log n)
- sc: O(n)

## pattern
- vertical order traversal
- column-wise traversal
- bfs with row and column coordinates
- sorting by column, then row, then value
- multiple nodes at same position

## blackbox
```cpp
vector<vector<int>> verticalTraversal(TreeNode* root) {

    vector<vector<int>> v;
    map<int,map<int,multiset<int>>> mp;
    queue<tuple<int,int,TreeNode*>> q;

    q.push({0,0,root});
    while (!q.empty()){

        auto [r,c,node] = q.front(); q.pop();
        mp[c][r].insert(node->val);

        if (node->left) q.push({r+1,c-1,node->left});
        if (node->right) q.push({r+1,c+1,node->right});

    }

    for (auto &c: mp) {

        vector<int> l;
        for (auto &r: c.second)
            for (auto &it: r.second)
                l.push_back(it);

        v.push_back(l);

    }

    return v;

}
```