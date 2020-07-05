/*

Method 1 : Using Iteration       Verdict Accepted

Complexity analysis

Time complexity : O(n). Assume that nn is the list's length, the time complexity is O(n).

Space complexity : O(1).

*/

ListNode* reverseList(ListNode* head) {
    ListNode* prev = NULL;
    ListNode* trav = head;

    while (trav) {
        ListNode* next = trav -> next;
        trav -> next = prev;
        prev = trav;
        trav = next;
    }

    return prev;

}

/*

Method 2 : Using recursion         Verdict Accepted

Complexity analysis

Time complexity : O(n). Assume that nn is the list's length, the time complexity is O(n).

Space complexity : O(n). The extra space comes from implicit stack space due to recursion. The recursion could go up to nn levels deep.


idea : key idea here is traverse list to end once we get the node with next as NULL it will be our new head and
       from there we will do our further operation.

*/

ListNode* reverseList(ListNode* head) {

    if (!head || !head -> next) {                 //It will take care of empty list,list with one element
        return head;                              //and also return last node
    }

    ListNode* revhead = reverseList(head -> next);
    head -> next -> next = head;
    head -> next = NULL;

    return revhead;
}