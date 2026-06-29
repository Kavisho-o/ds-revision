/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 */

// @lc code=start
class Solution {
public:

    int R,C;

    const vector<int> dr = {-1,1,0,0};
    const vector<int> dc = {0,0,-1,1};

    bool valid(int r, int c){

        return r>=0 && r<R && c>=0 && c<C;

    }

    int orangesRotting(vector<vector<int>>& grid) {

        R=grid.size();
        C=grid[0].size();

        queue<pair<int,int>> q;

        int fresh=0;
        for (int i=0; i<R; i++) for (int j=0; j<C; j++) {
            if (grid[i][j]==1) fresh++;
            else if (grid[i][j]==2) q.push({i,j});
        }

        int mins=-1;

        if (fresh==0) return 0;
        while (!q.empty()){

            int sz=q.size();
            mins++;

            for (int i=0; i<sz; i++){
                auto [x,y]=q.front(); q.pop();
                for (int k=0; k<4; k++){

                    int nx=x+dr[k], ny=y+dc[k];
                    if (valid(nx,ny) && grid[nx][ny]==1) {
                        grid[nx][ny]=2;    // mark
                        fresh--;
                        q.push({nx,ny});
                    }

                }
            }

        }

        if (fresh>0) return -1;
        return mins==-1 ? 0 : mins;
        
    }
};
// @lc code=end

