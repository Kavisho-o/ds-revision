## tortoise hare template (Floyd's Cycle Detection)
- tc: O(n)
- sc: O(1)

## pattern
- "cycle detection"
- "linked list cycle"
- "find duplicate number"
- "find cycle start"
- "happy number"
- "loop detection"
- "fast and slow pointer"

## algo
Initialize slow and fast pointers
Move slow by 1 step, fast by 2 steps
If they meet → cycle exists
To find cycle start:
Move one pointer to start
Move both 1 step
Meeting point = cycle start

## black box
```
ListNode *detectCycle(ListNode *head) {

    if (!head || !head->next) return NULL;

    ListNode *slow = head;
    ListNode *fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            slow = head;

            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }

            return slow;
        }
    }

    return NULL;
}
```

## find duplicate number (tortoise hare variation)

- pattern
"find duplicate number"
"array size n+1"
"numbers from 1 to n"
"only one duplicate"
"cannot modify array"

- black box
``` 
int findDuplicate(vector<int>& nums) {

    int slow = nums[0];
    int fast = nums[0];

    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    slow = nums[0];

    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }

    return slow;
}
```