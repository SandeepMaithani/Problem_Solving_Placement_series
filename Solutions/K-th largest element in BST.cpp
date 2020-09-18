/*

Method 1 : Using Reverse Inorder traversal and counter                          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

void reverseInorder(Node *root, int &answer, int &count) {
    if (root == NULL || count == 0) {
        return;
    }

    reverseInorder(root -> right, answer, count);

    count--;

    if (count == 0) {
        answer = root -> data;
    }

    reverseInorder(root -> left, answer, count);
}


int kthLargest(Node *root, int K)
{
    //Your code here

    int answer = -1;
    int count = K;

    reverseInorder(root, answer, count);

    return answer;
}


/*

Method 2 : Using Resverse Inorder traversal and storing elements                         Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). To to store elements during reverse inorder traversal.

*/

void reverseInorder(Node *root, vector<int> &elements) {
    if (root == NULL) {
        return;
    }

    reverseInorder(root -> right, elements);
    elements.push_back(root -> data);
    reverseInorder(root -> left, elements);
}


int kthLargest(Node *root, int K)
{
    //Your code here
    vector<int>elements;

    reverseInorder(root, elements);

    int answer = elements[K - 1];

    return answer;
}