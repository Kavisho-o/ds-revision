## prefix sum + hashmap template (this one is specifically subarray sum equals k)
- tc: O(n)
- sc: O(n)


## pattern
- "subarray sum equals k"
- "number of subarrays"
- "sum = k"
- "prefix sum"
- "count subarrays"
- "negative numbers allowed"


## algo
Maintain running prefix sum
If (prefix sum - k) already seen → add its frequency
Store current prefix sum in hashmap
Initialize hashmap with {0 : 1} (important for exact match from start)


## black box
```
int subarraySum(vector<int>& arr, int k) {

    unordered_map<int,int> mp;
    mp[0] = 1;

    int cnt = 0;
    int tot = 0;

    for (auto a : arr) {

        tot += a;

        if (mp.find(tot - k) != mp.end())
            cnt += mp[tot - k];

        mp[tot]++;
    }

    return cnt;
}
```


## very useful congruent
- longest subarray with sum k
```
int maxLength(vector<int>& arr, int k) {
        
    unordered_map<int,int> mp;
    
    int sum = 0;
    int maxi = 0;
    
    mp[0] = -1;   
    
    for(int i = 0; i < arr.size(); i++) {
        
        sum += arr[i];
        
        if(mp.find(sum-k) != mp.end()) {               // 
            maxi = max(maxi, i - mp[sum-k]);
        }
        else {
            mp[sum] = i;
        }
    }
    
    return maxi;
}
```
