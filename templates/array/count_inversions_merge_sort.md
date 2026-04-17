## merge sort inversion template (count inversions)
- tc: O(n log n)
- sc: O(n)


## pattern
- "count inversions"
- "reverse pairs"
- "count smaller after self"
- "count pairs i < j"
- "arr[i] > arr[j]"
- "count unordered pairs"
- "count swaps needed to sort"


## algo
- Use merge sort
- Split array into two halves
- Count inversions in left half
- Count inversions in right half
- Count cross inversions while merging
- Merge sorted halves


## key idea
Left half sorted
Right half sorted
If left[i] > right[j]
Then all elements from i → mid are inversions
count += (mid - i + 1)


## traditional merge sort 
```
class Solution {
public:
    void merge(vector<int>& nums, int low, int mid, int high) {

        vector<int> temp;
        int left = low, right = mid + 1;

        while (left <= mid && right <= high) {

            if (nums[left] <= nums[right]) temp.push_back(nums[left++]);
            else temp.push_back(nums[right++]);

        }

        while (left <= mid) {

            temp.push_back(nums[left++]);

        }

        while (right <= high) {

            temp.push_back(nums[right++]);

        }

        for (int i = low; i <= high; ++i) {

            nums[i] = temp[i - low];

        }

    }

    void mergeSort(vector<int>& nums, int low, int high) {

        if (low >= high) return;

        int mid = low + (high - low) / 2;

        mergeSort(nums, low, mid);
        mergeSort(nums, mid + 1, high);
        merge(nums, low, mid, high);

    }

    vector<int> sortArray(vector<int>& nums) {

        mergeSort(nums, 0, nums.size() - 1);
        return nums;
            
    }
};
```


## black box
```
class Solution {
private:

    int mergeAndCount(vector<int> &arr, int left, int mid, int right) {

        vector<int> temp;
        int i = left;
        int j = mid + 1;

        int inv = 0;

        while (i <= mid && j <= right) {

            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            }
            else {
                temp.push_back(arr[j++]);
                inv += (mid - i + 1);
            }
        }

        while (i <= mid) temp.push_back(arr[i++]);
        while (j <= right) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {
            arr[left + k] = temp[k];
        }

        return inv;
    }


    int mergeSort(vector<int> &arr, int left, int right) {

        int count = 0;

        if (left < right) {

            int mid = left + (right - left) / 2;

            count += mergeSort(arr, left, mid);
            count += mergeSort(arr, mid + 1, right);
            count += mergeAndCount(arr, left, mid, right);
        }

        return count;
    }

public:

    int inversionCount(vector<int>& arr) {

        return mergeSort(arr, 0, arr.size() - 1);
    }
};
```


## when to use this template

Use when:

- Need to count pairs efficiently
- Brute force is O(n²)
- Problem involves sorted order comparisons
- "Count while sorting" type problems