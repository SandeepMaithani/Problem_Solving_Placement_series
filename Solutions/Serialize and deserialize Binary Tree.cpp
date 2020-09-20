/*

Using PreOrder traversal                          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. Because we will be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

void serialize(Node *root, vector<int> &A)
{
    if (root == NULL) {
        A.push_back(-1);
        return;
    }

    A.push_back(root -> data);

    serialize(root -> left, A);
    serialize(root -> right, A);
}


Node * deserialHelper(vector<int> &A, int &index) {
    if (A[index] == -1) {
        index++;
        return NULL;
    }

    Node *root = new Node(A[index]);
    index++;

    root -> left = deserialHelper(A, index);
    root -> right = deserialHelper(A, index);

    return root;
}

Node * deSerialize(vector<int> &A)
{
    int index = 0;
    return deserialHelper(A, index);
}