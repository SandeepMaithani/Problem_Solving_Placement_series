
/*

Method 1: Single Pass Algorithm     Verdict : Accepted

Complexity Analysis

Time complexity : O(L).

The algorithm makes one traversal of the list of L nodes. Therefore time complexity is O(L).

Space complexity : O(1).

We only used constant extra space.

*/

ListNode* removeNthFromEnd(ListNode* head, int n) {

    ListNode dummy(0);
    dummy.next = head;

    ListNode* first = head;
    ListNode* second = &dummy;

    for (int i = 1; i <= n; i++) {
        first = first -> next;
    }

    while (first) {
        first = first -> next;
        second = second -> next;
    }

    second -> next = second -> next -> next;
    return dummy.next;

}


/*

Method 2: Two pass algorithm        Verdict : Accepted

Complexity Analysis

Time complexity : O(L).

The algorithm makes two traversal of the list, first to calculate list length L and second to find the (L - n)th node. There are 2L-n operations and time complexity is O(L).

Space complexity : O(1).

We only used constant extra space.

*/

ListNode* removeNthFromEnd(ListNode* head, int n) {

    int size = 0;
    ListNode* temp = head;

    while (temp) {
        size++;
        temp = temp -> next;
    }

    int mover = size - n + 1;

    if (size < n ) {
        return head -> next;
    }

    temp = head;
    ListNode* prev = head;
    size = 0;

    while (temp) {

        size++;

        if (size == mover) {
            if (prev == temp) {
                head = head -> next;
            }
            else {
                prev -> next = temp -> next;
            }
        }
        prev = temp;
        temp = temp -> next;

    }

    return head;

}

