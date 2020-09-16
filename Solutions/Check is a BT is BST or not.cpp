/*

Approach 1: Using Recursion and (Min - Max) Range.                               Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), Since we visit each node exactly once.

Space complexity : O(N), in the worst case of completely unbalanced tree, to keep a recursion stack and O(log(N)) in the best case of completely balanced tree.

*/


class Solution {
public:
    bool validHelper(TreeNode* root, long min, long max) {
        if (root == NULL) {
            return true;
        }
        if (root -> val <= min || root -> val >= max) {
            return false;
        }

        return (validHelper(root -> left, min, root -> val) && validHelper(root -> right, root -> val, max));
    }
    bool isValidBST(TreeNode* root) {
        return validHelper(root, LONG_MIN, LONG_MAX);
    }
};




/*

Approach 2: Using Inorder Traversal                               Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), Since we visit each node exactly once.

Space complexity : O(N), Because we are using a extra vector to store inorder traversal.

*/

class Solution {
public:
    void inOrder(TreeNode* root, vector<int>&traversal) {
        if (root == NULL) {
            return;
        }

        inOrder(root -> left, traversal);
        traversal.push_back(root -> val);
        inOrder(root -> right, traversal);
    }

    bool isValidBST(TreeNode* root) {

        if (root == NULL) {
            return true;
        }

        vector<int>traversal;

        inOrder(root, traversal);

        for (int i = 0; i < traversal.size() - 1; i++) {
            if (traversal[i] >= traversal[i + 1]) {
                return false;
            }
        }

        return true;

    }
};