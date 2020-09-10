/*

Complexity Analysis :

Time Complexity: O(N). where N is number of nodes in the binary tree.

Space Complexity: O(1). We are not using any extra space if function call stack is not concerned.

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return NULL;
        }

        if (p -> val == root -> val || q -> val == root -> val) {
            return root;
        }

        TreeNode* la = lowestCommonAncestor(root -> left, p, q);
        TreeNode* ra = lowestCommonAncestor(root -> right, p, q);

        if (la && ra) {
            return root;
        }
        else if (la) {
            return la;
        }
        else if (ra) {
            return ra;
        }

        return NULL;
    }
};