#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,popcnt")

#include <bits/stdc++.h>
using namespace std;

using ll  = long long;
using ld  = long double;
using vi  = vector<int>;
using vl  = vector<ll>;
using vvi = vector<vector<int>>;
using vvl = vector<vector<ll>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;

const int INF  = 2e9;
const ll  LINF = 4e18;
const ll  MOD  = 1e9+7;

#define all(x)        (x).begin(),(x).end()
#define rall(x)       (x).rbegin(),(x).rend()
#define pb            push_back
#define eb            emplace_back
#define fi            first
#define se            second
#define sz(x)         (int)(x).size()
#define rep(i,a,b)    for(int i=(a); i<(b); ++i)
#define rrep(i,a,b)   for(int i=(a); i>=(b); --i)
#define each(x,v)     for(auto& x : v)

auto chmin = [](auto& a, auto b){ return b<a ? a=b,true : false; };
auto chmax = [](auto& a, auto b){ return b>a ? a=b,true : false; };

class Solution {
public:

    int R, C;

    const vector<int> dr = {-1,1,0,0};
    const vector<int> dc = {0,0,-1,1};

    bool valid(int r, int c){

        return r>=0 && r<R && c>=0 && c<C;

    }

    // Grid DFS
    void dfs(vector<vector<char>>& grid, int r, int c) {

        if (!valid(r,c) || grid[r][c] != '1') return;

        grid[r][c] = '0';              
        for (int d=0; d<4; d++) dfs(grid, r+dr[d], c+dc[d]);

    }

    // Grid BFS
    int bfs(vector<vector<int>>& grid, int sr, int sc) {

        queue<pair<int,int>> q;
        q.push({sr, sc});

        grid[sr][sc] = -1;  
        int steps = 0;

        while (!q.empty()) {

            int n = q.size();

            while (n--) {

                auto p = q.front(); q.pop();
                int r = p.first;
                int c = p.second;

                for (int d=0; d<4; d++) {

                    int nr=r+dr[d], nc=c+dc[d];
                    if (valid(nr,nc) && grid[nr][nc]==0) q.push({nr,nc}), grid[nr][nc]=-1;

                }
            }
            steps++;

        }
        return steps;

    }

    // Union Find
    vector<int> par, rnk;

    int find(int x){ return par[x]==x ? x : par[x]=find(par[x]); }

    bool unite(int a, int b) {

        a=find(a); b=find(b);

        if(a==b) return false;
        if(rnk[a]<rnk[b]) swap(a,b);

        par[b]=a; if(rnk[a]==rnk[b]) rnk[a]++;
        return true;
        
    }
};