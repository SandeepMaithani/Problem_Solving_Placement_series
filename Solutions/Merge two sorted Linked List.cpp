/*

Method 2 : Using Recursion       Verdict Accepted

Complexity analysis

Time complexity : O(N + M). Assume that N and M are the length of lists, the time complexity is O(N + M) as only one traversal of linked list is needed.

Space complexity : O(N + M).If the recursive stack space is taken into consideration.

*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) {
        return l2;
    }
    else if (!l2) {
        return l1;
    }
    else if (l1 -> val <= l2 -> val) {
        l1 -> next = mergeTwoLists(l1 -> next, l2);
        return l1;
    }
    else {
        l2 -> next = mergeTwoLists(l1, l2 -> next);
        return l2;
    }
}

/*

Method 2 : Using Iteration       Verdict Accepted

Complexity analysis

Time complexity : O(N+M). Assume that N and M are the length of lists, the time complexity is O(N + M).

Space complexity : O(1)

*/

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode sorted(0);
    ListNode* tail = &sorted;

    while (l1 != NULL && l2 != NULL) {
        if (l1 -> val <= l2 -> val) {
            tail -> next = l1;
            tail = l1;
            l1 = l1 -> next;
        }
        else {
            tail -> next = l2;
            tail = l2;
            l2 = l2 -> next;
        }
    }

    if (l1 != NULL) {
        tail -> next = l1;
    }

    if (l2 != NULL) {
        tail -> next = l2;
    }

    return sorted.next;

}