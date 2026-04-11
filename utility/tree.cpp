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

struct TreeNode {

    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}

};

class Solution {
public:

    // DFS
    int dfs(TreeNode* node) {

        if (!node) return 0;           

        int L = dfs(node->left);
        int R = dfs(node->right);
        
        return max(L, R) + 1;          // example: height
    }

    // BFS
    vector<vector<int>> levelOrder(TreeNode* root) {

        vector<vector<int>> res;

        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {

            int n = q.size();
            vector<int> level;

            while (n--) {

                auto node = q.front(); q.pop();
                level.push_back(node->val);

                if (node->left)  q.push(node->left);
                if (node->right) q.push(node->right);

            }

            res.push_back(level);
        }

        return res;
    }

    
    int ans = INT_MIN;

    int gain(TreeNode* node) {

        if (!node) return 0;

        int L = max(0, gain(node->left));
        int R = max(0, gain(node->right));

        ans = max(ans, node->val + L + R);   
        return node->val + max(L, R);     

    }

    int maxPathSum(TreeNode* root) {

        gain(root);
        return ans;

    }
};