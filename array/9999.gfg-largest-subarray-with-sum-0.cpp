// https://www.geeksforgeeks.org/problems/largest-subarray-with-0-sum/1

#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

// template - pref sum + hash

// int subarraySum(vector<int>& arr, int k) {

//     unordered_map<int,int> mp;
//     mp[0] = 1;

//     int cnt = 0;
//     int tot = 0;

//     for (auto a : arr) {

//         tot += a;

//         if (mp.find(tot - k) != mp.end())
//             cnt += mp[tot - k];

//         mp[tot]++;
//     }

//     return cnt;
// }

class Solution {
  public:
    int maxLength(vector<int>& arr) {
        
        int n=arr.size();
        ll sum=0;

        int mx=-0;

        unordered_map<int,int> mp;
        mp[0]=-1;       // if pref sum becomes 0 at index i
                        // length = i - (-1) = i + 1

        for (int i=0; i<n; i++){

            sum+=arr[i];
            if (mp.find(sum)!=mp.end()) mx=max(mx,i-mp[sum]);  
            else mp[sum] = i;

        }   

        return mx;

    }
};