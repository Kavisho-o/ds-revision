/*
 * @lc app=leetcode id=547 lang=cpp
 *
 * [547] Number of Provinces
 */

// @lc code=start
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    void dfs(int node, vector<vector<int>> &v, vector<bool> &vis){

        vis[node]=1;
        for (int i=0; i<n; i++){
            if (v[node][i] && !vis[i]) dfs(i,v,vis);
        }

    }

    int findCircleNum(vector<vector<int>>& isConnected) {

        // couldve done this the traditional way 
        // but since some sorta adjacency list is already given
        // creating another would take unnecessary space
        // dfs better here

        n=isConnected.size();
        vector<bool> vis(n,0);

        int prov=0;
        for (int i=0; i<n; i++){
            if (!vis[i]){
                dfs(i,isConnected,vis);
                prov++;
            }
        }
        return prov;
        
    }
};
// @lc code=end

