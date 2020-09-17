/*

Method : Using BST Property and recursion                          Verdict : Accepted

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    if (root == NULL) {
        return;
    }

    if (root -> key == key) {

        if (root -> left != NULL) {
            Node* preHelper = root -> left;

            while (preHelper -> right) {
                preHelper = preHelper -> right;
            }

            pre = preHelper;
        }

        if (root -> right != NULL) {
            Node* sucHelper = root -> right;

            while (sucHelper -> left) {
                sucHelper = sucHelper -> left;
            }

            suc = sucHelper;
        }
    }
    else if (root -> key > key) {
        suc = root;
        findPreSuc(root -> left, pre, suc, key);
    }
    else {
        pre = root;
        findPreSuc(root -> right, pre, suc, key);
    }
}