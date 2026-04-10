/*
 * @lc app=leetcode id=88 lang=cpp
 *
 * [88] Merge Sorted Array
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

class Solution {
public:
    void merge(vector<int>& a, int m, vector<int>& b, int n) {

        int i=m-1;
        int j=n-1;
        int k=m+n-1;

        if (m==0) a=b;

        while (i>=0 && j>=0 && k>=0){

            if (a[i]>b[j]){
                a[k--]=a[i--];
            }
            else if(a[i]<b[j]){
                a[k--]=b[j--];
            }
            else{
                a[k--]=a[i--];
                a[k--]=b[j--];
            }

        }

        while (j>=0 && k>=0){    // remaining elems in b

            a[k--]=b[j--];
            
        }
        
    }
};
// @lc code=end

