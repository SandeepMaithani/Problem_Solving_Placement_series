/*

Complexity Analysis :

Time Complexity: O(n) Only one traversal of the loop is needed.

Space Complexity: O(1).

*/


Node* rotate(Node* head, int k)
{
    if (k == 0) {
        return head;
    }

    Node* temp = head;

    while (temp -> next) {
        temp = temp -> next;
    }

    temp -> next = head;

    Node* prev = NULL;
    temp = head;

    while (k--) {
        prev = temp;
        temp = temp -> next;
    }

    head = temp;
    prev -> next = NULL;

    return head;

}