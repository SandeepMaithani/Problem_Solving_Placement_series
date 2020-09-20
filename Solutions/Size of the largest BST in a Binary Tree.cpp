/*

Method : using preorder traversal and checking state of each node                     Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. We will be visiting each and every node.

Space Complexity: O(H). Where H is height of tree, which is occupied by our calling stack for the preorder traversal.

*/

struct info {
    bool isBST;
    int largestSize;
    int min;
    int max;
};

info treeHelper(Node *root) {
    if (root == NULL) {
        return {true, 0, INT_MAX, INT_MIN};
    }

    if (root -> left == NULL && root -> right == NULL) {
        return {true, 1, root -> data, root -> data};
    }

    info leftTree = treeHelper(root -> left);
    info rightTree = treeHelper(root -> right);

    info currentNode;

    currentNode.isBST = leftTree.isBST && rightTree.isBST && (root -> data > leftTree.max && root -> data < rightTree.min);
    currentNode.min = min(root -> data, min(leftTree.min, rightTree.min));
    currentNode.max = max(root -> data, max(leftTree.max, rightTree.max));

    if (currentNode.isBST) {
        currentNode.largestSize = leftTree.largestSize + rightTree.largestSize + 1;
    }
    else if (leftTree.largestSize > rightTree.largestSize) {
        currentNode.largestSize = leftTree.largestSize;
    }
    else {
        currentNode.largestSize = rightTree.largestSize;
    }

    return currentNode;
}

int largestBst(Node *root)
{
    info solution = treeHelper(root);
    return solution.largestSize;
}




/*

resource : Pepcoding Sumit sir

*/