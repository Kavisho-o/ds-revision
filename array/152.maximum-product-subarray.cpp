/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {

        // kadane
        // normal kadane assumes negative numbers as always undesirable cause they only ever hurt the sum
        // but here negative numbers can be useful
        // so we track max as well as min
        
        int maxProd = nums[0];
        int minProd = nums[0];
        int ans = nums[0];
        
        for(int i=1; i<nums.size(); i++){
            
            int temp = maxProd;
            
            maxProd = max({nums[i], nums[i]*maxProd, nums[i]*minProd});
            minProd = min({nums[i], nums[i]*temp, nums[i]*minProd});
            
            ans = max(ans, maxProd);
            
        }
        
        return ans;
    }
};

// @lc code=end

