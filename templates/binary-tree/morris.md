## Morris Preorder Traversal
- tc: O(n)
- sc: O(1)

## pattern
- preorder traversal without recursion
- preorder traversal without stack
- constant space tree traversal
- threaded binary tree traversal

## blackbox
```cpp
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
```

---

## Morris Inorder Traversal
- tc: O(n)
- sc: O(1)

## pattern
- inorder traversal without recursion
- inorder traversal without stack
- constant space tree traversal
- threaded binary tree traversal

## blackbox
```cpp
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
```