/*

Approach: Swap with Next Node       Verdict : Accepted

Complexity Analysis

Time and space complexity are both O(1).


*/


void deleteNode(ListNode* node) {

	ListNode* nextnode = node -> next;

	node -> val = nextnode -> val;
	node -> next = nextnode -> next;

	delete nextnode;

}