/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int pmn = INT_MAX;
        int mx = 0;

        for (auto &p: prices){

            pmn = min(pmn,p);
            mx = max(mx,p-pmn);

        }

        return mx;
        
    }
};
// @lc code=end

