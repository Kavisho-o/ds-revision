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

    void dfs(TreeNode* node, vvi &res, vi &path){

        path.pb(node->val);

        if (!node->left && !node->right) res.pb(path);
        
        else{
            if (node->left) dfs(node->left,res,path);
            if (node->right) dfs(node->right,res,path);
        }

        path.pop_back();
        
    }

    vvi rtlp(TreeNode* root){

        vvi res;
        vi path;
        dfs(root,res,path);
        return res;

    }

};

int main() {

    Solution sol;

    vector<TreeNode*> tests;

    // --------------------------------------------------
    // Tree 1
    //
    //         1
    //       /   \
    //      2     3
    //     / \     \
    //    4   5     6
    //
    // Expected:
    // 1 2 4
    // 1 2 5
    // 1 3 6
    // --------------------------------------------------

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    t1->right->right = new TreeNode(6);

    tests.push_back(t1);


    // --------------------------------------------------
    // Tree 2
    //
    //      10
    //
    // Expected:
    // 10
    // --------------------------------------------------

    TreeNode* t2 = new TreeNode(10);

    tests.push_back(t2);


    // --------------------------------------------------
    // Tree 3
    //
    //      1
    //       \
    //        2
    //         \
    //          3
    //           \
    //            4
    //
    // Expected:
    // 1 2 3 4
    // --------------------------------------------------

    TreeNode* t3 = new TreeNode(1);
    t3->right = new TreeNode(2);
    t3->right->right = new TreeNode(3);
    t3->right->right->right = new TreeNode(4);

    tests.push_back(t3);


    // --------------------------------------------------
    // Tree 4
    //
    //          8
    //        /   \
    //       4     12
    //      / \    /
    //     2   6  10
    //
    // Expected:
    // 8 4 2
    // 8 4 6
    // 8 12 10
    // --------------------------------------------------

    TreeNode* t4 = new TreeNode(8);
    t4->left = new TreeNode(4);
    t4->right = new TreeNode(12);
    t4->left->left = new TreeNode(2);
    t4->left->right = new TreeNode(6);
    t4->right->left = new TreeNode(10);

    tests.push_back(t4);


    // --------------------------------------------------
    // Tree 5
    //
    //            5
    //          /   \
    //         3     8
    //        /     / \
    //       1     7   9
    //        \
    //         2
    //
    // Expected:
    // 5 3 1 2
    // 5 8 7
    // 5 8 9
    // --------------------------------------------------

    TreeNode* t5 = new TreeNode(5);
    t5->left = new TreeNode(3);
    t5->right = new TreeNode(8);
    t5->left->left = new TreeNode(1);
    t5->left->left->right = new TreeNode(2);
    t5->right->left = new TreeNode(7);
    t5->right->right = new TreeNode(9);

    tests.push_back(t5);


    for (int i = 0; i < (int)tests.size(); i++) {

        cout << "Tree " << i + 1 << ":\n";

        auto ans = sol.rtlp(tests[i]);

        for (auto &path : ans) {
            for (int x : path)
                cout << x << " ";
            cout << '\n';
        }

        cout << '\n';
    }

    return 0;
}

/*

Expected Terminal Output

Tree 1:
1 2 4
1 2 5
1 3 6

Tree 2:
10

Tree 3:
1 2 3 4

Tree 4:
8 4 2
8 4 6
8 12 10

Tree 5:
5 3 1 2
5 8 7
5 8 9

*/