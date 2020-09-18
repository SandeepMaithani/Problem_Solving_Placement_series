/*

Method 1 : Using Inorder traversal and counter                          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

void inorder(Node* root, int &answer, int &count) {

    if (root == NULL) {
        return;
    }

    if (count <= 0) {
        return;
    }

    inorder(root -> left, answer, count);

    count--;

    if (count == 0) {
        answer = root -> data;
    }

    inorder(root -> right, answer, count);

}

int KthSmallestElement(Node *root, int k)
{
    //add code here.

    int answer = -1;
    int count = k;

    inorder(root, answer, count);

    return answer;
}



/*

Method 2 : Using Inorder traversal and storing elements                         Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). To to store elements during inorder traversal.

*/

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>&elements) {

        if (root == NULL) {
            return;
        }

        inOrder(root -> left, elements);
        vec.push_back(root -> elements);
        inOrder(root -> right, elements);
    }

    int kthSmallest(TreeNode* root, int k) {

        if (root == NULL) {
            return -1;
        }

        vector<int>elements;

        inod(root, elements);

        int answer = elements[k - 1];

        return answer;

    }
};