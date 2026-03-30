## hashset sequence template (this one is specifically longest consecutive sequence)
- tc: O(n)
- sc: O(n)


## pattern
- "longest consecutive"
- "longest streak"
- "continuous integers"
- "longest chain"
- "consecutive elements"
- "sequence of numbers"


## algo
- Insert all elements into hashset
- Iterate through each number
- If num - 1 not present → start sequence
- Expand using num + 1
- Track max length


## black box
```
int longestConsecutive(vector<int>& nums) {

    unordered_set<int> st(nums.begin(), nums.end());

    int mx = 0;

    for (auto num : st) {

        if (!st.count(num - 1)) {

            int cur = num;
            int len = 1;

            while (st.count(cur + 1)) {
                cur++;
                len++;
            }

            mx = max(mx, len);
        }
    }
}
```