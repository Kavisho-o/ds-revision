## reverse linked list template
- tc: O(n)
- sc: O(1)

## black box
```
ListNode* reverseList(ListNode* head) {

    ListNode* prev = NULL;
    ListNode* curr = head;

    while (curr) {
        ListNode* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}
```

- recursive reverse (optional)
## black box
```
ListNode* reverseList(ListNode* head) {

    if (!head || !head->next) return head;

    ListNode* newHead = reverseList(head->next);

    head->next->next = head;
    head->next = NULL;

    return newHead;
}
```