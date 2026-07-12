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

    // vector<vector<int>> levelOrder(TreeNode* root){

    //     vector<vector<int>> v;
    //     queue<TreeNode*> q;
    //     q.push(root);

    //     while (!q.empty()){

    //         vector<int> l;
    //         int sz = q.size();

    //         for (int i=0; i<sz; i++){

    //             TreeNode* node=q.front(); q.pop();
    //             l.push_back(node->val);

    //             if (node->left) q.push(node->left);
    //             if (node->right) q.push(node->right);

    //         }

    //         v.push_back(l);
    //     }

    //     return v;

    // }

    // void recursiveInorder(TreeNode* root, vector<int> &v){

    //     // left -> root -> right

    //     if (!root) return;
    //     if (root->left) recursiveInorder(root->left,v);
    //     v.push_back(root->val);
    //     if (root->right) recursiveInorder(root->right,v);

    // }

    // void recursivePreorder(TreeNode* root, vector<int> &v){

    //     // root -> left -> right

    //     if (!root) return;
    //     v.push_back(root->val);
    //     if (root->left) recursivePreorder(root->left,v);
    //     if (root->right) recursivePreorder(root->right,v);

    // }

    // void recursivePostorder(TreeNode* root, vector<int> &v){

    //     // left -> right -> root

    //     if (!root) return;
    //     if (root->left) recursivePostorder(root->left,v);
    //     if (root->right) recursivePostorder(root->right,v);
    //     v.push_back(root->val);

    // }

    // vector<int> morrisPreorder(TreeNode* root){

    //     vector<int> v;
    //     if (!root) return v;

    //     TreeNode* curr = root;
    //     while (curr){

    //         TreeNode* ptr = curr->left;

    //         if (ptr){                              // left found -> go to the rightmost node of this subtree

    //             while (ptr->right && ptr->right!=curr) ptr = ptr->right;

    //             if (ptr->right==curr){            // a thread already exists here -> break it, use curr and move on to its right

    //                 ptr->right = nullptr;         // to free up redundant space
    //                 curr = curr->right;

    //             }

    //             else{                            // create a thread to the root and move to its left

    //                 ptr->right = curr;
    //                 v.push_back(curr->val);
    //                 curr = curr->left;

    //             }
    //         }

    //         else{                               // no left found -> move on to right

    //             v.push_back(curr->val);
    //             curr = curr->right;

    //         }

    //     }
    //     return v;

    // }

    // vector<int> morrisInorder(TreeNode* root){

    //     vector<int> v;
    //     if (!root) return v;

    //     TreeNode* curr = root;
    //     while (curr){

    //         TreeNode* ptr = curr->left;

    //         if (ptr){                              // left found -> go to the rightmost node of this subtree

    //             while (ptr->right && ptr->right!=curr) ptr = ptr->right;

    //             if (ptr->right==curr){            // a thread already exists here -> break it, use curr and move on to its right

    //                 ptr->right = nullptr;         // to free up redundant space
    //                 v.push_back(curr->val);
    //                 curr = curr->right;

    //             }

    //             else{                            // create a thread to the root and move to its left

    //                 ptr->right = curr;
    //                 curr = curr->left;

    //             }
    //         }

    //         else{                               // no left found -> move on to right

    //             v.push_back(curr->val);
    //             curr = curr->right;

    //         }

    //     }
    //     return v;

    // }

    vector<int> top(TreeNode* root){

        int mn=INT_MAX;
        int mx=INT_MIN;
        vector<int> v;

        unordered_map<int,int> mp;
        queue<pair<int,TreeNode*>> q;

        q.push({0,root});
        while (!q.empty()){

            auto [c,node] = q.front(); q.pop();
            if (mp.find(c)==mp.end()) mp[c]=node->val;

            mn=min(mn,c);
            mx=max(mx,c);

            if (node->left) q.push({c-1,node->left});
            if (node->right) q.push({c+1,node->right});
        }

        for (int i=mn; i<=mx; i++) v.push_back(mp[i]);
        return v;

    }

    vector<int> bottom(TreeNode* root){

        int mn=INT_MAX;
        int mx=INT_MIN;
        vector<int> v;

        unordered_map<int,int> mp;
        queue<pair<int,TreeNode*>> q;

        q.push({0,root});
        while (!q.empty()){

            auto [c,node] = q.front(); q.pop();
            mp[c]=node->val;

            mn=min(mn,c);
            mx=max(mx,c);

            if (node->left) q.push({c-1,node->left});
            if (node->right) q.push({c+1,node->right});
        }

        for (int i=mn; i<=mx; i++) v.push_back(mp[i]);
        return v;

    }
};

int main() {

    Solution sol;

    // ============================================================
    // Tree 1
    //
    //         1
    //        / \
    //       2   3
    //
    // Top View    : 2 1 3
    // Bottom View : 2 1 3
    // ============================================================

    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);


    // ============================================================
    // Tree 2
    //
    //            1
    //          /   \
    //         2     3
    //        / \   / \
    //       4  5  6   7
    //
    // Top View    : 4 2 1 3 7
    // Bottom View : 4 2 6 3 7
    // ============================================================

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);

    tree2->left->left = new TreeNode(4);
    tree2->left->right = new TreeNode(5);

    tree2->right->left = new TreeNode(6);
    tree2->right->right = new TreeNode(7);


    // ============================================================
    // Tree 3
    //
    //          1
    //         /
    //        2
    //       /
    //      3
    //     /
    //    4
    //
    // Top View    : 4 3 2 1
    // Bottom View : 4 3 2 1
    // ============================================================

    TreeNode* tree3 = new TreeNode(1);
    tree3->left = new TreeNode(2);
    tree3->left->left = new TreeNode(3);
    tree3->left->left->left = new TreeNode(4);


    // ============================================================
    // Tree 4
    //
    //    1
    //     \
    //      2
    //       \
    //        3
    //         \
    //          4
    //
    // Top View    : 1 2 3 4
    // Bottom View : 1 2 3 4
    // ============================================================

    TreeNode* tree4 = new TreeNode(1);
    tree4->right = new TreeNode(2);
    tree4->right->right = new TreeNode(3);
    tree4->right->right->right = new TreeNode(4);


    // ============================================================
    // Tree 5
    //
    //             10
    //           /    \
    //          5      20
    //         / \       \
    //        3   7       30
    //           /       /
    //          6       25
    //
    // Top View    : 3 5 10 20 30
    // Bottom View : 3 6 25 30
    // ============================================================

    TreeNode* tree5 = new TreeNode(10);

    tree5->left = new TreeNode(5);
    tree5->right = new TreeNode(20);

    tree5->left->left = new TreeNode(3);
    tree5->left->right = new TreeNode(7);

    tree5->left->right->left = new TreeNode(6);

    tree5->right->right = new TreeNode(30);
    tree5->right->right->left = new TreeNode(25);


    // ============================================================
    // Top View
    // ============================================================

    vector<int> t1 = sol.top(tree1);
    for (int x : t1) cout << x << " ";
    cout << endl;

    vector<int> t2 = sol.top(tree2);
    for (int x : t2) cout << x << " ";
    cout << endl;

    vector<int> t3 = sol.top(tree3);
    for (int x : t3) cout << x << " ";
    cout << endl;

    vector<int> t4 = sol.top(tree4);
    for (int x : t4) cout << x << " ";
    cout << endl;

    vector<int> t5 = sol.top(tree5);
    for (int x : t5) cout << x << " ";
    cout << endl << endl;


    // ============================================================
    // Bottom View
    // ============================================================

    vector<int> b1 = sol.bottom(tree1);
    for (int x : b1) cout << x << " ";
    cout << endl;

    vector<int> b2 = sol.bottom(tree2);
    for (int x : b2) cout << x << " ";
    cout << endl;

    vector<int> b3 = sol.bottom(tree3);
    for (int x : b3) cout << x << " ";
    cout << endl;

    vector<int> b4 = sol.bottom(tree4);
    for (int x : b4) cout << x << " ";
    cout << endl;

    vector<int> b5 = sol.bottom(tree5);
    for (int x : b5) cout << x << " ";
    cout << endl;

    return 0;

    // terminal expected output:
    // 2 1 3
    // 4 2 1 3 7
    // 4 3 2 1
    // 1 2 3 4
    // 3 5 10 20 30

    // 2 1 3
    // 4 2 6 3 7
    // 4 3 2 1
    // 1 2 3 4
    // 3 6 7 25 30
}