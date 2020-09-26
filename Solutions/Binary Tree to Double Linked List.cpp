/*

Method 1 :- Using Inorder traversal and Tail Pointer                               Verdict :- Accepted

Complexity Analysis :-

Time Complexity: O(N), where N is the Number of Nodes in the tree as we will be visiting all the nodes of the Binary tree in every case.

Space Complexity: O(N) or O(1), in the worst case of completely unbalanced tree, to keep a recursion stack and if we ignore in calling stack space then it will take O(1) extra space.

*/


void dllHelper(Node *root, Node * &head, Node * &tail) {
    if (root == NULL) {
        return;
    }

    dllHelper(root -> left, head, tail);

    if (head == NULL) {
        head = root;
    }
    else {
        root -> left = tail;
        tail -> right = root;
    }

    tail = root;

    dllHelper(root -> right, head, tail);
}

Node * bToDLL(Node *root)
{
    Node *head = NULL;
    Node *tail = NULL;

    dllHelper(root, head, tail);

    return head;
}



/*

Method 2 :- Using Inorder traversal and new node                               Verdict :- Accepted

Complexity Analysis :-

Time Complexity: O(N), where N is the Number of Nodes in the tree as we will be visiting all the nodes of the Binary tree in every case.

Space Complexity: O(N), We are creating a new node each time when we are done with processing a node.

*/


void dllHelper(Node *root, Node * &head, Node * &tail) {
    if (root == NULL) {
        return;
    }

    dllHelper(root -> left, head, tail);

    Node *temp = new Node();
    temp -> data = root -> data;

    if (head == NULL) {
        head = temp;
    }
    else {
        temp -> left = tail;
        tail -> right = temp;
    }

    tail = temp;

    dllHelper(root -> right, head, tail);
}

Node * bToDLL(Node *root)
{
    Node *head = NULL;
    Node *tail = NULL;

    dllHelper(root, head, tail);

    return head;
}
