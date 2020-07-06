/*

Complexity Analysis

Time complexity : O(max(m,n)). Assume that m and n represents the length of l1 and l2 respectively, our algorithm  iterates at most max(m,n) times.

Space complexity : O(max(m,n)). The length of the new list is at most max(m,n)+1.

*/

//NOTE :- Here No are stored in reverse order in our linked list

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;

    ListNode result(0);
    ListNode* l3 = &result;

    while (l1 && l2) {
        int a = l1 -> val;
        int b = l2 -> val;

        int sum = a + b + carry;
        carry = sum / 10;

        l3 -> next = new ListNode(sum % 10);

        l3 = l3 -> next;
        l1 = l1 -> next;
        l2 = l2 -> next;
    }

    while (l1) {

        int sum = (l1 -> val) + carry;
        carry = sum / 10;
        l3 -> next = new ListNode(sum % 10);
        l3 = l3 -> next;
        l1 = l1 -> next;
    }

    while (l2) {

        int sum = (l2 -> val) + carry;
        carry = sum / 10;
        l3 -> next = new ListNode(sum % 10);
        l3 = l3 -> next;
        l2 = l2 -> next;
    }

    if (carry) {

        l3 -> next = new ListNode(carry);
        carry = carry / 10;
        l3 = l3 -> next;
    }

    return result.next;

}