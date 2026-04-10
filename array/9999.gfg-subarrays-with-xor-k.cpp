// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        
        unordered_map<int,int> mp;
        mp[0]=1;
        
        int Xor=0;
        long cnt=0;
        
        for (int a: arr){
            
            Xor^=a;
            if (mp.find(Xor^k)!=mp.end()) cnt+=mp[Xor^k];
            mp[Xor]++;
            
        }
        
        return cnt;
    }
};