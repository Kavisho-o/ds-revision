/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int cur=0;
        int mx=INT_MIN;

        for (auto n: nums){

            cur=max(n,cur+n);
            mx=max(mx,cur);

        }

        return mx;
        
    }
};

/* if asked to print that subarray:
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {

        int cur = 0;
        int mx = INT_MIN;

        int start = 0, end = 0, tempStart = 0;

        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] > cur + nums[i]) {
                cur = nums[i];
                tempStart = i;
            } else {
                cur += nums[i];
            }

            if (cur > mx) {
                mx = cur;
                start = tempStart;
                end = i;
            }
        }

        vector<int> result;
        for (int i = start; i <= end; i++) {
            result.push_back(nums[i]);
        }

        return result;
    }
};
*/


// @lc code=end

