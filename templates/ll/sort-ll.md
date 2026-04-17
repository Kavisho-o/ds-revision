## linked list merge sort (sort list)
- tc: O(n log n)
- sc: O(log n) (recursion stack) / O(1) iterative variant

## pattern
- "sort linked list"
- "merge sort on linked list"
- "stable sort list"
- "divide list into halves"
- "sort without extra array"

## algo
- Base case → if head is null or single node → return
- Find middle of linked list using slow-fast pointers
- Split list into two halves (break at mid)
- Recursively sort left and right halves
- Merge two sorted linked lists

## black box
```
// find middle (prev to mid for splitting)
ListNode* mn(ListNode* head) {

    ListNode *slow = head, *fast = head, *prev = nullptr;

    while (fast && fast->next) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    return prev;  // node before mid
}

// merge two sorted lists
ListNode* merge(ListNode* l, ListNode* r){

    ListNode temp(-1);
    ListNode* s = &temp;

    while (l && r){

        if (l->val > r->val) {
            s->next = r;
            r = r->next;
        }
        else{
            s->next = l;
            l = l->next;
        }

        s = s->next;
    }

    if (l) s->next = l;
    if (r) s->next = r;

    return temp.next;
}

// merge sort
ListNode* sortList(ListNode* head){

    if (!head || !head->next) return head;

    ListNode* mid = mn(head);

    ListNode* l = head;
    ListNode* r = mid->next;

    mid->next = nullptr;

    l = sortList(l);
    r = sortList(r);

    return merge(l,r);
}
```

## intuition 
- Array merge sort uses indices → LL uses pointers
- Splitting is tricky → use slow-fast + prev
- No extra space needed for merging → reuse nodes
- Stable + optimal for linked list sorting