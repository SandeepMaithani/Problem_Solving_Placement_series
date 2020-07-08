/*

METHOD 1 : Floyd’s Cycle-Finding Algorithm          Verdict : Accepted

Complexity Analysis

Time Complexity: O(n) Only one traversal of the loop is needed.

Space Complexity: O(1).

*/

ListNode *detectCycle(ListNode *head) {

	ListNode *slow = head;
	ListNode *fast = head;

	while (fast && fast -> next) {
		slow = slow -> next;
		fast = fast -> next -> next;

		if ( slow == fast) {
			break;
		}
	}

	if (!fast || !fast -> next) {
		return NULL;
	}

	fast = head;

	while (slow != fast) {
		slow = slow -> next;
		fast = fast -> next;
	}

	return slow;

}


/*

METHOD 2 : Hashing         Verdict : Accepted

Complexity Analysis

Time Complexity: O(n) Only one traversal of the loop is needed.

Space Complexity: O(1) n is the space required to store the value in hashmap.

*/

ListNode *detectCycle(ListNode *head) {

	unordered_set<ListNode*>hashset;

	while (head) {

		if (hashset.find(head) != hashset.end()) {

			return head;
		}
		else {

			hashset.insert(head);
		}

		head = head -> next;
	}
	return NULL;
}