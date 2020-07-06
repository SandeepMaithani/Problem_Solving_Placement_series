/*

Approach 1: Two Pointers           Verdict : Accepted

Complexity Analysis

Time complexity : O(m+n).

Space complexity : O(1).

*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    ListNode *temp1 = headA;
    ListNode *temp2 = headB;

    while (temp1 != temp2) {

        if (temp1 == NULL) {
            temp1 = headB;
        }
        else {
            temp1 = temp1 -> next;
        }

        if (temp2 == NULL) {
            temp2 = headA;
        }
        else {
            temp2 = temp2 -> next;
        }

    }

    return temp2;
}

/*

Approach 2: Hash Table           Verdict : Accepted

Complexity Analysis

Time complexity : O(m+n).

Space complexity : O(m) or O(n).

*/

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {

    unordered_map<ListNode*, int>hashmap;

    while (headA) {
        hashmap[headA]++;
        headA = headA -> next;
    }

    while (headB) {
        if (hashmap.find(headB) != hashmap.end()) {
            return headB;
        }
        headB = headB -> next;
    }

    return NULL;
}