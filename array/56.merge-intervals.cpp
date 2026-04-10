/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long 

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& arr) {

        vector<vector<int>> v;
        int n=arr.size();
        sort(arr.begin(),arr.end());

        int start = arr[0][0];
        int pend = arr[0][1];
        for (int i=1; i<n; i++){

            if (pend>=arr[i][0]) pend = max(pend,arr[i][1]);
            else{

                vector<int> varr = {start,pend};
                v.pb(varr);

                start = arr[i][0];
                pend = arr[i][1];

            }

        }

        vector<int> varr = {start,pend};
        v.pb(varr);

        return v;
        
    }
};
// @lc code=end

