#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findNumberOfComponent(int V, vector<vector<int>> &edges) {

        // building adjacency list first

        vector<vector<int>> adj(V);
        for (int i=0; i<edges.size(); i++){

            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);    

        }

        queue<int> q;
        vector<bool> vis(V,0);
        int cc=0;

        for (int i=0; i<V; i++){

            if (!vis[i]){

                cc++;
                vis[i]=1;
                q.push(i);

                while (!q.empty()){

                    int p=q.front(); q.pop();
                    for (auto &a: adj[p]) if (!vis[a]){

                        q.push(a);
                        vis[a]=1;

                    }
                }
            }

        }
        return cc;

    }
};

int main() {
    Solution obj;

    // Test Case 1
    int V = 4;
    vector<vector<int>> edges = {
        {0, 1},
        {1, 2}
    };

    cout << obj.findNumberOfComponent(V, edges) << endl;   // 2


    // Test Case 2
    V = 7;
    edges = {
        {0, 1},
        {1, 2},
        {2, 3},
        {4, 5}
    };

    cout << obj.findNumberOfComponent(V, edges) << endl;   // 3


    // Test Case 3
    V = 8;
    edges = {
        {0, 1},
        {3, 4},
        {6, 7}
    };

    cout << obj.findNumberOfComponent(V, edges) << endl;   // 5

    return 0;
}