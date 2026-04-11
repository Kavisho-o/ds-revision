## interval merge template (overlapping intervals)
- tc: O(n log n)
- sc: O(1) or O(n) (depending on output)

## pattern
- "merge intervals"
- "overlapping intervals"
- "combine intervals"
- "meeting rooms"
- "insert interval"
- "union of intervals"
- "calendar scheduling"

## algo
- Sort intervals by start time
- Initialize start and end from first interval
- Iterate through intervals
- If overlapping → update end = max(end, current_end)
- Else → push previous interval and reset start, end
- Push last interval

## black box
```
vector<vector<int>> merge(vector<vector<int>>& arr) {

    vector<vector<int>> v;
    int n = arr.size();

    sort(arr.begin(), arr.end());

    int start = arr[0][0];
    int end = arr[0][1];

    for (int i = 1; i < n; i++) {

        if (end >= arr[i][0]) {
            end = max(end, arr[i][1]);
        } 
        else {
            v.push_back({start, end});
            start = arr[i][0];
            end = arr[i][1];
        }
    }

    v.push_back({start, end});

    return v;
}
```