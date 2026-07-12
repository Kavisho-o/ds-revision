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

    vector<int> in,pre,pos;

    void solve(TreeNode* root){

        if (root==nullptr) return;

        stack<pair<TreeNode*,int>> st;
        st.push({root,1});
        
        while (!st.empty()){

            auto &[node,state] = st.top(); st.pop();

            if (state==1){              // preorder state: push left

                pre.push_back(node->val);
                state++;
                st.push({node,state});
                
                if (node->left) st.push({node->left,1});
            }

            else if (state==2){        // inorder state: push right

                in.push_back(node->val);
                state++;
                st.push({node,state});

                if (node->right) st.push({node->right,1});
            }
 
            else{                     // postorder state: no push

                pos.push_back(node->val);

            }

        }

    }

};



int main() {

    Solution sol;

    auto print = [&](TreeNode* root, const string& name) {

        sol.in.clear();
        sol.pre.clear();
        sol.pos.clear();

        sol.solve(root);

        cout << "========== " << name << " ==========\n";

        cout << "Preorder : ";
        for (int x : sol.pre) cout << x << " ";
        cout << '\n';

        cout << "Inorder  : ";
        for (int x : sol.in) cout << x << " ";
        cout << '\n';

        cout << "Postorder: ";
        for (int x : sol.pos) cout << x << " ";
        cout << "\n\n";
    };

    // ============================================================
    // Tree 1 (Perfect Binary Tree)
    //
    //          1
    //        /   \
    //       2     3
    //      / \   / \
    //     4  5  6  7
    //
    // Pre : 1 2 4 5 3 6 7
    // In  : 4 2 5 1 6 3 7
    // Post: 4 5 2 6 7 3 1
    // ============================================================

    TreeNode* t1 = new TreeNode(1);
    t1->left = new TreeNode(2);
    t1->right = new TreeNode(3);
    t1->left->left = new TreeNode(4);
    t1->left->right = new TreeNode(5);
    t1->right->left = new TreeNode(6);
    t1->right->right = new TreeNode(7);

    print(t1, "Tree 1");


    // ============================================================
    // Tree 2 (Left Skewed)
    //
    //      1
    //     /
    //    2
    //   /
    //  3
    // /
    //4
    //
    // Pre : 1 2 3 4
    // In  : 4 3 2 1
    // Post: 4 3 2 1
    // ============================================================

    TreeNode* t2 = new TreeNode(1);
    t2->left = new TreeNode(2);
    t2->left->left = new TreeNode(3);
    t2->left->left->left = new TreeNode(4);

    print(t2, "Tree 2");


    // ============================================================
    // Tree 3 (Right Skewed)
    //
    //1
    // \
    //  2
    //   \
    //    3
    //     \
    //      4
    //
    // Pre : 1 2 3 4
    // In  : 1 2 3 4
    // Post: 4 3 2 1
    // ============================================================

    TreeNode* t3 = new TreeNode(1);
    t3->right = new TreeNode(2);
    t3->right->right = new TreeNode(3);
    t3->right->right->right = new TreeNode(4);

    print(t3, "Tree 3");


    // ============================================================
    // Tree 4 (Asymmetric)
    //
    //          10
    //         /  \
    //        5    15
    //         \   /
    //          8 12
    //
    // Pre : 10 5 8 15 12
    // In  : 5 8 10 12 15
    // Post: 8 5 12 15 10
    // ============================================================

    TreeNode* t4 = new TreeNode(10);
    t4->left = new TreeNode(5);
    t4->right = new TreeNode(15);
    t4->left->right = new TreeNode(8);
    t4->right->left = new TreeNode(12);

    print(t4, "Tree 4");


    // ============================================================
    // Tree 5 (Random)
    //
    //            8
    //          /   \
    //         3     10
    //        / \      \
    //       1   6      14
    //          / \     /
    //         4   7   13
    //
    // Pre : 8 3 1 6 4 7 10 14 13
    // In  : 1 3 4 6 7 8 10 13 14
    // Post: 1 4 7 6 3 13 14 10 8
    // ============================================================

    TreeNode* t5 = new TreeNode(8);
    t5->left = new TreeNode(3);
    t5->right = new TreeNode(10);
    t5->left->left = new TreeNode(1);
    t5->left->right = new TreeNode(6);
    t5->left->right->left = new TreeNode(4);
    t5->left->right->right = new TreeNode(7);
    t5->right->right = new TreeNode(14);
    t5->right->right->left = new TreeNode(13);

    print(t5, "Tree 5");

    return 0;
}