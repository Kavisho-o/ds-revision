// https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
  private:

    int mergeAndCount(vector<int> &arr, int left, int mid, int right) {

        vector<int> temp;

        int i = left;     
        int j = mid + 1;  

        int invCount = 0;

        while (i <= mid && j <= right) {

            if (arr[i] <= arr[j]) {
                temp.push_back(arr[i++]);
            } 
            
            else {
                temp.push_back(arr[j++]);
                invCount += (mid - i + 1); 
            }

        }

        while (i <= mid) temp.push_back(arr[i++]);

        while (j <= right) temp.push_back(arr[j++]);

        for (int k = 0; k < temp.size(); k++) {

            arr[left + k] = temp[k];
            
        }

        return invCount;

    }


    int mergeSortAndCount(vector<int> &arr, int left, int right) {

        int invCount = 0;

        if (left < right) {

            int mid = left + (right - left) / 2;
            invCount += mergeSortAndCount(arr, left, mid);
            invCount += mergeSortAndCount(arr, mid + 1, right);
            invCount += mergeAndCount(arr, left, mid, right);

        }

        return invCount;
    }


  public:

    int inversionCount(vector<int> &arr) {

        int ans = mergeSortAndCount(arr,0,arr.size()-1);
        return ans;
        
    }
};