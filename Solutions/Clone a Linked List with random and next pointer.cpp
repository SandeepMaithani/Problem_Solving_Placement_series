/*

Method 1 : Inserting clone node at middle or original node                     verdict : Accepted

Complexity Analysis:

Time Complexity: O(N). We will traverse each Node at most twice.

Space complexity : O(1). we don't require additional space in our program.

*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) {
            return head;
        }

        Node* helper = head;
        Node* temp;

        while (helper != NULL) {
            temp = helper -> next;
            helper -> next = new Node(helper -> val);
            helper -> next -> next = temp;
            helper = temp;
        }

        helper = head;

        while (helper != NULL) {
            if (helper -> next != NULL && helper -> random != NULL) {
                helper -> next -> random = helper -> random -> next;
            }

            helper = helper -> next != NULL ? helper -> next -> next : helper -> next;
        }

        Node* copy = head -> next;
        Node* original = head;
        temp = copy;

        while (original != NULL && copy != NULL) {
            original -> next = original -> next != NULL ? original -> next ->next : original -> next;
            copy -> next = copy -> next != NULL ? copy -> next -> next : copy -> next;

            original = original -> next;
            copy = copy -> next;
        }

        return temp;
    }
};



/*

Method 2 : Using Hashing                          verdict : Accepted

Complexity Analysis:

Time Complexity: O(N). We will traverse each Node at most twice.

Space complexity : O(N). We are using a hashMap to map clone Node and original Node.

*/


/*

Intution :- The idea is to use Hashing

1. Traverse the original linked list and make a copy in terms of data.

2. Make a hash map of key value pair with original linked list node and copied linked list node.

3. Traverse the original linked list again and using the hash map adjust the next and random reference of cloned linked list nodes.

*/


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* headHelper = head;
        Node* dummy = new Node(0);
        Node* helper = dummy;
        unordered_map<Node*, Node*>hashMap;

        while (headHelper != NULL) {
            Node* newNode = new Node(headHelper -> val);
            helper -> next = newNode;
            hashMap[headHelper] = newNode;
            helper = newNode;
            headHelper = headHelper -> next;
        }

        headHelper = head;
        helper = dummy -> next;

        while (headHelper != NULL && helper != NULL) {
            helper -> random = hashMap[headHelper -> random];
            helper = helper -> next;
            headHelper = headHelper -> next;
        }

        return dummy -> next;

    }
};