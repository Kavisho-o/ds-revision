## used for finding max subarray sum with array with both positives and negatives
- tc: O(n)
- sc: O(1)


## pattern 
- "maximum subarray sum"
- "largest contiguous sum"
- "maximum profit type problem"
- "subarray with best score"

## blackbox
```
int maxSubArray(vector<int>& nums) {
    int maxSum = INT_MIN, currSum = 0;
    for(int x : nums){
        currSum += x;
        maxSum = max(maxSum, currSum);
        if(currSum < 0) currSum = 0;
    }
    return maxSum;
}
```