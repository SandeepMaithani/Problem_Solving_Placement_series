/*

Method 1 : Using Iterative Approach                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(H), Where H is height of tree, H == N in the worst case of completely unbalanced tree and in the best case of completely balanced tree H == Log(N).

Space complexity : O(1), No Extra space required.

*/


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        TreeNode* helper = root;

        while (helper) {
            if (val == helper -> val) {
                break;
            }
            if (val < helper -> val) {
                helper = helper -> left;
            }
            else {
                helper = helper -> right;
            }
        }

        return helper;
    }
};


/*

Method 2 : Using recursion                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(H), Where H is height of tree, H == N in the worst case of completely unbalanced tree and in the best case of completely balanced tree H == Log(N).

Space complexity : O(N), in the worst case of completely unbalanced tree, to keep a recursion stack and O(log(N)) in the best case of completely balanced tree.

*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {

        if (root == NULL) {
            return NULL;
        }

        if (root -> val == val) {
            return root;
        }
        if (val < root -> val) {
            return searchBST(root -> left, val);
        }
        if (val > root -> val) {
            return searchBST(root -> right, val);
        }

        return NULL;

    }
};