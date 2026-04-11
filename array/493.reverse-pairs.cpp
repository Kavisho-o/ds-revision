/*
 * @lc app=leetcode id=493 lang=cpp
 *
 * [493] Reverse Pairs
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

class Solution {
public:

    ll merge(vector<int> &arr, int l, int m, int r){

        ll cnt = 0;
        int j = m + 1;

        for (int i = l; i <= m; i++) {

            while (j<=r && (ll)arr[i]>2LL*arr[j]) {

                j++;

            }

            cnt += (j - (m + 1));

        }

        vector<int> v;

        int i = l;
        j = m + 1;

        while (i <= m && j <= r){

            if (arr[i] <= arr[j]) v.pb(arr[i++]);
            else v.pb(arr[j++]);
            
        }

        while (i <= m) v.pb(arr[i++]);
        while (j <= r) v.pb(arr[j++]);

        for (int k = 0; k < v.size(); k++) {

            arr[l + k] = v[k];

        }

        return cnt;
        
    }

    ll mcnt(vector<int> &arr, int i, int j){

        ll cnt=0;

        if (i<j) {

            int mid = i + (j-i)/2;

            cnt += mcnt(arr, i, mid);
            cnt += mcnt(arr, mid + 1, j);

            cnt += merge(arr, i, mid, j);

        }

        return cnt;

    }
    int reversePairs(vector<int>& arr) {

        ll ans = mcnt(arr,0,arr.size()-1);
        return ans;
        
    }
};
// @lc code=end

