## index marking template (missing + repeating / duplicate detection)
- tc: O(n)
- sc: O(1)

## technique name
- Index Marking / Sign Marking / In-place Hashing

## pattern
- "missing and repeating number"
- "find duplicate in array 1 to n"
- "find missing number"
- "find all duplicates"
- "array contains numbers from 1 to n"
- "constant space required"
- "no extra array allowed"

## when to use
- Numbers range from 1 to n
- You are allowed to modify the array
- Need O(1) extra space
- Often used in:
1. Missing + repeating
2. Find duplicate
3. Find all missing numbers
4. Find first duplicate

## black box
```
vector<int> findTwoElement(vector<int>& arr) {

    int n = arr.size();
    int rep = -1;
    long long sum = 0;

    for (int i = 0; i < n; i++) {

        int idx = abs(arr[i]) - 1;

        if (arr[idx] < 0)
            rep = abs(arr[i]);
        else
            arr[idx] = -arr[idx];

        sum += abs(arr[i]);
    }

    int mis = (long long)n * (n + 1) / 2 - (sum - rep);

    return {rep, mis};
}
```