// https://www.geeksforgeeks.org/problems/given-a-linked-list-of-0s-1s-and-2s-sort-it/1

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

class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

// struct ListNode {

//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}

// };

class Solution {
public:

    // // dummy head
    // ListNode* removeElements(ListNode* head, int val) {

    //     ListNode dummy(0, head);
    //     ListNode* cur = &dummy;

    //     while (cur->next) {

    //         if (cur->next->val == val) cur->next = cur->next->next;
    //         else cur = cur->next;

    //     }

    //     return dummy.next;

    // }

    // floyd's
    Node* middleNode(Node* head) {

        Node *slow = head, *fast = head;

        while (fast && fast->next) {

            slow = slow->next;
            fast = fast->next->next;

        }

        return slow;  // middle (or 2nd middle if even length)
    }

    // ListNode* reverse(ListNode* head) {

    //     ListNode* prev = nullptr;

    //     while (head) {

    //         auto nxt = head->next;
    //         head->next = prev;
    //         prev = head;
    //         head = nxt;

    //     }

    //     return prev;
    // }

    // // floyd's

    // bool hasCycle(ListNode* head) {

    //     ListNode *slow = head, *fast = head;

    //     while (fast && fast->next) {

    //         slow = slow->next;
    //         fast = fast->next->next;

    //         if (slow == fast) return true;

    //     }

    //     return false;
    // }

    Node* segregate(Node* head) {
        
        Node* zhead = new Node(-1);
        Node* ohead = new Node(-1);
        Node* thead = new Node(-1);
        
        Node* ztail = zhead;
        Node* otail = ohead;
        Node* ttail = thead;

        Node* curr = head;

        while (curr){

            if (curr->data==0) { ztail->next=curr; ztail = curr; }
            else if (curr->data==1) { otail->next=curr; otail = curr; }
            else { ttail->next = curr; ttail = curr; }

            curr = curr->next;

        }

        if (ohead->next) ztail->next = ohead->next;
        else ztail->next = thead->next;

        otail->next = thead->next;
        ttail->next = nullptr;

        head = zhead->next;
        delete zhead, ohead, thead;

        return head;
        
    }
};


