/*

METHOD 1 : Floyd’s Cycle-Finding Algorithm          Verdict : Accepted

Complexity Analysis

Time Complexity: O(n) Only one traversal of the loop is needed.

Space Complexity: O(1).

*/

void removeLoop(Node* head)
{
    Node* fast = head;
    Node* slow = head;

    while (fast && fast -> next) {

        slow = slow -> next;
        fast = fast -> next -> next;

        if (slow == fast) {
            break;
        }
    }

    if (slow == head) {

        while (slow -> next != head) {

            slow = slow->next;
        }
        slow->next = NULL;
    }

    if (slow == fast) {

        slow = head;

        while (slow -> next != fast -> next) {
            slow = slow -> next;
            fast = fast -> next;
        }
        fast -> next = NULL;
    }
}