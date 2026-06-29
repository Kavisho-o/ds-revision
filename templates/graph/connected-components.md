## Connected Components (BFS)
- tc: O(V + E)
- sc: O(V + E)


## pattern
- "connected components"
- "number of components"
- "count components"
- "undirected graph"
- "disconnected graph"
- "groups of connected nodes"


## algo
- Build adjacency list from edge list
- Maintain a visited array
- Traverse every vertex
- If vertex is unvisited:
  - Increment component count
  - Perform BFS/DFS from it
  - Mark all reachable vertices as visited
- Return component count


## black box
```cpp
int findNumberOfComponent(int V, vector<vector<int>> &edges) {

    vector<vector<int>> adj(V);

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> vis(V, false);
    queue<int> q;
    int cc = 0;

    for (int i = 0; i < V; i++) {

        if (!vis[i]) {

            cc++;
            vis[i] = true;
            q.push(i);

            while (!q.empty()) {

                int node = q.front();
                q.pop();

                for (auto nbr : adj[node]) {

                    if (!vis[nbr]) {
                        vis[nbr] = true;
                        q.push(nbr);
                    }
                }
            }
        }
    }

    return cc;
}
```