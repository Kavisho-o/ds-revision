/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        unordered_set<int> st(nums.begin(), nums.end());
        int mx = 0;

        for (auto s : st) {

            if (!st.count(s - 1)) {

                int cur = s;
                int len = 1;

                while (st.count(cur + 1)) {
                    cur++;
                    len++;
                }

                mx = max(mx, len);
            }
        }

        return mx;
    }
};
// @lc code=end

