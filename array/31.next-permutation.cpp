/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {

        int n = nums.size();
        int i = n - 1;

        for (; i >= 1; i--){
            if (nums[i-1] < nums[i]) break; 
        }

        if (i == 0){
            reverse(nums.begin(), nums.end());
            return;
        }

        int j = n - 1;

        for (; j >= i; j--){
            if (nums[j] > nums[i-1]) break;
        }

        swap(nums[i-1], nums[j]);
        reverse(nums.begin() + i, nums.end());
        
    }
};

// @lc code=end

