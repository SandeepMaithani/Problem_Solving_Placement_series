/*

Complexity Analysis :

Time complexity : O(N), It can take a worst case c=time complexity of O(N) in case of a skewed  Binary Search tree.

Space complexity : O(N), in the worst case of completely unbalanced tree, to keep a recursion stack and O(log(N)) in the best case of completely balanced tree.

*/


class Solution {
public:
    TreeNode* insertHelper(TreeNode* root, int val) {
        if (root == NULL) {
            root = new TreeNode(val);
        }
        else if (val < root -> val) {
            root -> left = insertHelper(root -> left, val);
        }
        else {
            root -> right = insertHelper(root -> right, val);
        }

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if (preorder.size() == 0) {
            return NULL;
        }

        TreeNode* root = NULL;

        for (int i = 0; i < preorder.size(); i++) {
            root = insertHelper(root, preorder[i]);
        }

        return root;
    }
};