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
#define rep(i,a,b)    for(int i=(a); i<(b); i++)
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

    // we perform 2 bfs'es 
    // 1. to build parent-child relationship
    // 2. to burn

    int timeToBurnTree(TreeNode* root, int start){

        unordered_map<int,TreeNode*> mp;   // child -> parent
        TreeNode* target=nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){

            int sz=sz(q);
            rep(i,0,sz){

                auto node=q.front(); q.pop();
                if (node->val==start) target=node;
                
                if (node->left) {

                    q.push({node->left});
                    mp[node->left->val]=node;

                }
                if (node->right) {

                    q.push({node->right});
                    mp[node->right->val]=node;

                }

            }

        }

        unordered_map<int,int> vis;

        q.push(target);
        vis[target->val]=1;

        int sec=-1;

        while (!q.empty()){

            int sz=sz(q);
            rep(i,0,sz){

                auto node=q.front(); q.pop();
                vis[node->val]=1;

                if (node->left && !vis[node->left->val]) q.push({node->left});
                if (node->right && !vis[node->right->val]) q.push({node->right});
                if (mp[node->val] && !vis[mp[node->val]->val]) q.push({mp[node->val]});

            }
            sec++;

        }

        return sec;

	}	

    // int height(TreeNode* root) {

    //     if (!root) return 0;
    //     int h=1;
    //     h+=max(height(root->left),height(root->right));
    //     return h;
        
    // }

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

};

int main() {

    Solution sol;

    // ============================================================
    // Test 1
    // Balanced tree
    //
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4  5  6   7
    //
    // Start = 5
    // ============================================================

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    t1->right->left = new TreeNode(6);
    t1->right->right = new TreeNode(7);

    cout << sol.timeToBurnTree(t1, 5) << endl;
    // Expected: 4



    // ============================================================
    // Test 2
    // Left skewed tree
    //
    //      1
    //     /
    //    2
    //   /
    //  3
    // /
    //4
    //
    // Start = 4
    // ============================================================

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->left->left = new TreeNode(3);
    t2->left->left->left = new TreeNode(4);

    cout << sol.timeToBurnTree(t2, 4) << endl;
    // Expected: 3



    // ============================================================
    // Test 3
    // Right skewed tree
    //
    // 1
    //  \
    //   2
    //    \
    //     3
    //      \
    //       4
    //
    // Start = 2
    // ============================================================

    TreeNode* t3 = new TreeNode(1);
    t3->right = new TreeNode(2);
    t3->right->right = new TreeNode(3);
    t3->right->right->right = new TreeNode(4);

    cout << sol.timeToBurnTree(t3, 2) << endl;
    // Expected: 2



    // ============================================================
    // Test 4
    // Single node
    //
    //      10
    //
    // Start = 10
    // ============================================================

    TreeNode* t4 = new TreeNode(10);

    cout << sol.timeToBurnTree(t4, 10) << endl;
    // Expected: 0



    // ============================================================
    // Test 5
    // Asymmetric tree
    //
    //             1
    //           /   \
    //          2     3
    //         /     / \
    //        4     5   6
    //       /           \
    //      7             8
    //
    // Start = 7
    // ============================================================

    TreeNode* t5 = new TreeNode(1);
    t5->left = new TreeNode(2);
    t5->right = new TreeNode(3);

    t5->left->left = new TreeNode(4);
    t5->left->left->left = new TreeNode(7);

    t5->right->left = new TreeNode(5);
    t5->right->right = new TreeNode(6);
    t5->right->right->right = new TreeNode(8);

    cout << sol.timeToBurnTree(t5, 7) << endl;
    // Expected: 6

    return 0;
}