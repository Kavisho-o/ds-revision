/*
 * @lc app=leetcode id=18 lang=cpp
 *
 * [18] 4Sum
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ll long long

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int t) {

        vector<vector<int>> v;
        sort(arr.begin(),arr.end());
        int n=arr.size();
        if (n<4) return v;

        for (int i=0; i<n-3; i++){

            if (i!=0 && arr[i-1]==arr[i]) continue;

            for (int j=i+1; j<n-2; j++){

                if (j!=i+1 && arr[j-1]==arr[j]) continue;
                int k=j+1;
                int l=n-1;

                while (k<l){

                    ll sum = (ll)arr[i]+arr[j]+arr[k]+arr[l];

                    if (sum==t) {

                        vector<int> temp = {arr[i],arr[j],arr[k],arr[l]};
                        sort(temp.begin(),temp.end());
                        v.pb(temp);
                        l--;
                        k++;
                        while (k<l && arr[k]==arr[k-1]) k++;
                        while (k<l && arr[l]==arr[l+1]) l--; 

                    }

                    else if (sum<t){

                        k++;

                    }

                    else{

                        l--;

                    }

                }

            }

        }

        return v;
        
    }
};
// @lc code=end

