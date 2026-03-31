/*
 * @lc app=leetcode id=2149 lang=cpp
 *
 * [2149] Rearrange Array Elements by Sign
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {

        int n=nums.size();

        int pos=0;
        int neg=1;

        vector<int> res(n);

        for (auto &n : nums){

            if (n<0) {
                res[neg]=n;
                neg+=2;
            }

            else{
                res[pos]=n;
                pos+=2;
            }

        }

        return res;

        
    }
};
// @lc code=end

