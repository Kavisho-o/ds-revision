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

    vector<vector<int>> levelOrder(TreeNode* root){

        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){

            vector<int> l;
            int sz = q.size();

            for (int i=0; i<sz; i++){

                TreeNode* node=q.front(); q.pop();
                l.push_back(node->val);

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

            }

            v.push_back(l);
        }

        return v;

    }

    void recursiveInorder(TreeNode* root, vector<int> &v){

        // left -> root -> right

        if (!root) return;
        if (root->left) recursiveInorder(root->left,v);
        v.push_back(root->val);
        if (root->right) recursiveInorder(root->right,v);

    }

    void recursivePreorder(TreeNode* root, vector<int> &v){

        // root -> left -> right

        if (!root) return;
        v.push_back(root->val);
        if (root->left) recursivePreorder(root->left,v);
        if (root->right) recursivePreorder(root->right,v);

    }

    void recursivePostorder(TreeNode* root, vector<int> &v){

        // left -> right -> root

        if (!root) return;
        if (root->left) recursivePostorder(root->left,v);
        if (root->right) recursivePostorder(root->right,v);
        v.push_back(root->val);

    }

    vector<int> morrisPreorder(TreeNode* root){

        vector<int> v;
        if (!root) return v;

        TreeNode* curr = root;
        while (curr){

            TreeNode* ptr = curr->left;

            if (ptr){                              // left found -> go to the rightmost node of this subtree

                while (ptr->right && ptr->right!=curr) ptr = ptr->right;

                if (ptr->right==curr){            // a thread already exists here -> break it, use curr and move on to its right

                    ptr->right = nullptr;         // to free up redundant space
                    curr = curr->right;

                }

                else{                            // create a thread to the root and move to its left

                    ptr->right = curr;
                    v.push_back(curr->val);
                    curr = curr->left;

                }
            }

            else{                               // no left found -> move on to right

                v.push_back(curr->val);
                curr = curr->right;

            }

        }
        return v;

    }

    vector<int> morrisInorder(TreeNode* root){

        vector<int> v;
        if (!root) return v;

        TreeNode* curr = root;
        while (curr){

            TreeNode* ptr = curr->left;

            if (ptr){                              // left found -> go to the rightmost node of this subtree

                while (ptr->right && ptr->right!=curr) ptr = ptr->right;

                if (ptr->right==curr){            // a thread already exists here -> break it, use curr and move on to its right

                    ptr->right = nullptr;         // to free up redundant space
                    v.push_back(curr->val);
                    curr = curr->right;

                }

                else{                            // create a thread to the root and move to its left

                    ptr->right = curr;
                    curr = curr->left;

                }
            }

            else{                               // no left found -> move on to right

                v.push_back(curr->val);
                curr = curr->right;

            }

        }
        return v;

    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {

        vector<vector<int>> v;
        map<int,map<int,multiset<int>>> mp;
        queue<tuple<int,int,ListNode*>> q;

        q.push({0,0,root});
        while (!q.empty()){

            auto [r,c,node] = q.front(); q.pop();
            mp[c][r].insert(node->val);

            if (node->left) q.push({row+1,col-1,node->left});
            if (node->right) q.push({row+1,col+1,node->right});
 
        }

        for (auto &c: mp) {

            vector<int> l;
            for (auto &it: c.second.second) l.push_back(it);
            v.push_back(l);

        }

        return v;
        
    }

};
