// https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1

#include <bits/stdc++.h>
using namespace std;

#define pb push_back 
#define ll long long 

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {

        int n=arr.size();
        int rep=-1;

        ll sum=0;
        
        for (int i=0; i<n; i++){

            if (arr[abs(arr[i])-1]<0) rep=abs(arr[i]);
            else arr[abs(arr[i])-1] = -arr[abs(arr[i])-1];
            sum+=abs(arr[i]);

        }

        int mis = (ll)n*(n+1)/2 - (sum-rep);
        return {rep,mis};
        
    }
};