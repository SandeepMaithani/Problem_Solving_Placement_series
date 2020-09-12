/*

Method 1 : Using recursion                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely
unbalanced tree, to keep a recursion stack.

*/

bool areMirror(Node* a, Node* b) {
    if (a == NULL && b == NULL) {
        return true;
    }

    if (a != NULL && b != NULL && a -> data == b -> data) {

        return (areMirror(a -> left, b -> right) && areMirror(a -> right , b -> left));
    }

    return false;
}


/*

Method 2 : Using Iteration                          Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(N). We are using a helper queue which will have size of (2 * max child at any node).

*/

bool areMirror(Node* a, Node* b) {
    queue<Node*>helper;

    helper.push(a);
    helper.push(b);

    while (!helper.empty()) {

        Node* leftTree = helper.front();
        helper.pop();

        Node* rightTree = helper.front();
        helper.pop();

        if (leftTree == NULL && rightTree == NULL) {
            continue;
        }

        if ((leftTree != NULL && rightTree == NULL) || (leftTree == NULL && rightTree != NULL) || (leftTree -> data != rightTree -> data)) {

            return false;
        }

        helper.push(leftTree -> left);
        helper.push(rightTree -> right);
        helper.push(leftTree -> right);
        helper.push(rightTree -> left);
    }

    return true;
}

