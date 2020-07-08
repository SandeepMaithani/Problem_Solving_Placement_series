/*

First way  by making a cycle in linked list

Complexity Analysis

Time Complexity: O(n) Only one traversal of the loop is needed.

Space Complexity: O(1).

*/


ListNode* rotateRight(ListNode* head, int k) {

    if (head == NULL || head -> next == NULL) {
        return head;
    }

    ListNode* temp = head;
    int size = 1;

    while (temp -> next) {

        size++;
        temp = temp -> next;

    }

    int dis = k % size;

    if (dis == 0) {
        return head;
    }

    temp -> next = head;
    temp = head;
    int pos = size - dis - 1;

    while (pos--) {
        temp = temp -> next;
    }

    head = temp -> next;
    temp -> next = NULL;


    return head;

}

/*

second way using first and second pointer

Complexity Analysis

Time Complexity: O(n) Only one traversal of the loop is needed.

Space Complexity: O(1).

*/


ListNode* rotateRight(ListNode* head, int k) {

    if (head == NULL || head -> next == NULL) {
        return head;
    }

    ListNode* temp = head;
    int size = 0;

    while (temp) {

        size++;
        temp = temp -> next;

    }

    int dis = k % size;

    if (dis == 0) {
        return head;
    }


    ListNode* first = head;
    ListNode* second = head;


    while (dis--) {
        second = second -> next;
    }

    while (second -> next) {
        first = first -> next;
        second = second -> next;
    }

    temp = first -> next;
    first -> next = NULL;
    second -> next = head;
    head = temp;

    return head;

}