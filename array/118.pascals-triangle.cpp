/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start

#include <bits/stdc++.h>
using namespace std;

#define pb push_back

class Solution {
public:
    vector<vector<int>> generate(int numRows) {

        vector<vector<int>> ans;
        ans.push_back({1});

        for (int i=1; i<numRows; i++){

            vector<int> curr;
            curr.push_back(1);

            for (int j=0; j<ans.back().size()-1; j++) curr.push_back(ans.back()[j]+ans.back()[j+1]);

            curr.push_back(1);
            ans.push_back(curr);

        }
        
        return ans;
    }
};
// @lc code=end

