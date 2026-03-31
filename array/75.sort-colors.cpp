/*
 * @lc app=leetcode id=75 lang=cpp
 *
 * [75] Sort Colors
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& arr) {

        int n=arr.size()-1;
        int s=0;   // 0
        int e=n;   // 2
        int mid=0; // 1 

        while (mid<=e){

            if (arr[mid]==0) swap(arr[mid++],arr[s++]);
            else if (arr[mid]==2) swap(arr[mid],arr[e--]);
            else mid++;

        }
        
    }
};

// @lc code=end

