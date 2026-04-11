## permutation type template (this one is specifically next permutation)
- tc: O(n)
- sc: O(1)


## pattern 
- "next lexicographical"
- "next arrangement"
- "same digits"
- "generate permutations"
- "k-th permutation"


## algo
- Find first decreasing element from right
- If not found, just reverse the entire thing and return
- Find next greater element from right
- Swap
- Reverse right part

## black box
```
void nextPermutation(vector<int>& nums) {
    int i = nums.size() - 1;
    while (i > 0 && nums[i-1] >= nums[i]) {
        i--;
    }
    
    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    int j = nums.size() - 1;
    while (j >= i && nums[j] <= nums[i-1]) {
        j--;
    }
    
    swap(nums[i-1], nums[j]);
    reverse(nums.begin() + i, nums.end());        
}
```