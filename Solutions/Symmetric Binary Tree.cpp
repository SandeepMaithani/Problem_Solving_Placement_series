/*

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.

*/

class Solution {
public:

    bool mirrorHelper(TreeNode* root1, TreeNode* root2) {
        if (root1 == NULL && root2 == NULL) {
            return true;
        }
        if (root1 != NULL && root2 != NULL && root1 -> val == root2 -> val) {

            return (mirrorHelper(root1 -> left, root2 -> right) && mirrorHelper(root1 -> right, root2 -> left));
        }

        return false;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return mirrorHelper(root -> left, root -> right);
    }

};