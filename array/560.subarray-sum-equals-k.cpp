/*
 * @lc app=leetcode id=560 lang=cpp
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {

        unordered_map<int,int> mp;
        mp[0]=1;
        int cnt=0;
        int tot = 0;
        for (auto a: arr){

            tot+=a;
            if (mp.find(tot-k)!=mp.end()) cnt+=mp[tot-k];
            mp[tot]++;

        }

        return cnt;
        
    }
};
// @lc code=end

