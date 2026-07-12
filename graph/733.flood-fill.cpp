/*
 * @lc app=leetcode id=733 lang=cpp
 *
 * [733] Flood Fill
 */

// @lc code=start
#include <bits/stdc++.>
using namespace std;

class Solution {
public:

    int R,C;

    const vector<int> dr = {-1,1,0,0};
    const vector<int> dc = {0,0,-1,1};

    bool valid(int r, int c){

        return r>=0 && r<R && c>=0 && c<C;

    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        R=image.size();
        C=image[0].size();

        vector<vector<int>> vis(R,vector<int> (C,0));
        queue<pair<int,int>> q;
        q.push({sr,sc});
        vis[sr][sc]=1;

        while (!q.empty()){

            int r=q.front().first;
            int c=q.front().second;

            int pc=image[sr][sc];
            image[sr][sc]=color;

            for (int d=0; d<4; d++){

                int nr=r+dr[d], nc=c+dc[dc];
                if (valid(nr,nc) && !vis[nr][nc]) {

                    vis[nr][nc]=1;
                    if (image[nr][nc]==pc) image[nr][nc]=color;

                }
                
            }

        }
        
        return image;
    }
};
// @lc code=end

