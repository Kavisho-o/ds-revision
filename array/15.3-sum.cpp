/*
 * @lc app=leetcode id=15 lang=cpp
 *
 * [15] 3Sum
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& arr) {

        sort(arr.begin(),arr.end());

        vector<vector<int>> v;
        int n = arr.size();

        for (int i=0; i<n; i++){

            int j=i+1;
            int k=n-1;

            while (j<k){

                int sum = arr[i]+arr[j]+arr[k];
                if (sum==0){
                    vector<int> temp = {arr[i],arr[j],arr[k]};
                    sort(temp.begin(),temp.end());
                    v.pb(temp);
                }
                else if (sum<0){
                    j++;
                }
                else{
                    k--;
                }

            }

        }

        return v;
        
    }
};
// @lc code=end

