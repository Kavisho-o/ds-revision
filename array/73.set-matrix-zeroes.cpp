/*
 * @lc app=leetcode id=73 lang=cpp
 *
 * [73] Set Matrix Zeroes
 */

// @lc code=start

# include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& arr) {

        int n = arr.size();
        int m = arr[0].size();

        bool firstRow = false, firstCol = false;

        for (int i = 0; i < n; i++) {
            if (arr[i][0] == 0) firstCol = true;
        }

        for (int j = 0; j < m; j++) {
            if (arr[0][j] == 0) firstRow = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (arr[i][j] == 0) {
                    arr[i][0] = 0;
                    arr[0][j] = 0;
                }
            }
        }

        for (int i = 1; i < n; i++) {
            if (arr[i][0] == 0) {
                for (int j = 1; j < m; j++) {
                    arr[i][j] = 0;
                }
            }
        }

        for (int j = 1; j < m; j++) {
            if (arr[0][j] == 0) {
                for (int i = 1; i < n; i++) {
                    arr[i][j] = 0;
                }
            }
        }

        if (firstRow) {
            for (int j = 0; j < m; j++) {
                arr[0][j] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < n; i++) {
                arr[i][0] = 0;
            }
        }
    }
};
// @lc code=end

