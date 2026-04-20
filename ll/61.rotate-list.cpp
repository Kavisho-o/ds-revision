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

struct ListNode {

    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}

};

class Solution {
public:

    // dummy head
    // ListNode* removeElements(ListNode* head, int val) {

    //     ListNode dummy(0, head);
    //     ListNode* cur = &dummy;

    //     while (cur->next) {

    //         if (cur->next->val == val) cur->next = cur->next->next;
    //         else cur = cur->next;

    //     }

    //     return dummy.next;

    // }

    // // floyd's
    // ListNode* middleNode(ListNode* head) {

    //     ListNode *slow = head, *fast = head;

    //     while (fast && fast->next) {

    //         slow = slow->next;
    //         fast = fast->next->next;

    //     }

    //     return slow;  // middle (or 2nd middle if even length)
    // }

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

    ListNode* rotateRight(ListNode* head, int k) {

        int n=0;
        ListNode* temp = head;
        while (temp) {temp = temp->next; n++; }

        k%=n;
        if (k==0) return head;

        ListNode *prev = nullptr, *curr = head, *next = nullptr;
        while (curr){

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;

        }

        ListNode* shead = prev, *sprev = nullptr, *snext = nullptr;  // shead = prev is the head of first (entire list) reversal
        int cnt=0; 

        while (shead && cnt<k){

            snext = shead->next;
            shead->next = sprev;

            sprev = shead;
            shead = snext;

        }
        
        ListNode *thead = shead, *tprev = nullptr, *tnext = nullptr;   // thead = shead is the tail of second reversal (so the head of third reversal)
        while (thead){

            tnext = thead->next;
            thead->next = tprev;

            tprev = thead;
            thead = tnext;

        }

        ListNode* tail = sprev;     
        while (tail->next) tail = tail->next;
        tail->next = tprev;
        
        return sprev;  // head of second reversal
    }
};

