/*

METHOD 1 : By reversing list from mid           Verdict : Accepted

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the given list.

Space Complexity: O(1)

*/

ListNode* reverse(ListNode* head) {
    ListNode* prev = NULL;

    while (head) {
        ListNode* temp = head -> next;
        head -> next = prev;
        prev = head;
        head = temp;
    }
    return prev;
}

bool isPalindrome(ListNode* head) {

    ListNode* fast = head;
    ListNode* slow = head;

    while (fast && fast -> next) {
        slow = slow -> next;
        fast = (fast -> next) -> next;
    }

    ListNode* rev = reverse(slow);
    fast = head;

    while (rev) {
        if (rev -> val != fast -> val) {
            return false;
        }
        rev = rev -> next;
        fast = fast -> next;
    }

    return true;
}


/*

METHOD 2 : Using a Stack          Verdict : Accepted

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the given list.

Space Complexity: O(N), the space used by Stack.

*/

bool isPalindrome(ListNode* head) {

    stack<int>s;
    ListNode* temp = head;

    while (temp) {
        s.push(temp -> val);
        temp = temp -> next;
    }

    temp = head;

    while (temp) {
        int data = s.top();
        s.pop();

        if (data != temp -> val) {
            return false;
        }

        temp = temp -> next;
    }

    return true;

}