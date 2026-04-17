## linked list intersection, Y-shaped ll (two pointers trick)
- tc: O(n + m)
- sc: O(1)

## black box
```
ListNode *getIntersectionNode(ListNode *a, ListNode *b) {

    if (!a || !b) return nullptr;

    ListNode* ahead = a;
    ListNode* bhead = b;

    while (a != b) {

        a = a ? a->next : bhead;
        b = b ? b->next : ahead;

    }

    return a; // intersection or nullptr
}
```

## intuition
Core problem: length mismatch
One list longer → pointers don’t align initially
Trick:
After switching heads, both pointers travel:
lenA + lenB
lenB + lenA
→ equal distance covered
So:
If intersection exists → they meet there
If not → both hit nullptr together