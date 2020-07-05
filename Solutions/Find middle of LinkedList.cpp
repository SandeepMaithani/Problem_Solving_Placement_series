/*

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the given list.

Space Complexity: O(1), the space used by slow and fast.

*/

ListNode* middleNode(ListNode* head) {
    if (!head || !head -> next) {
        return head;
    }
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast -> next) {
        slow = slow -> next;
        fast = (fast -> next) -> next;
    }

    return slow;
}