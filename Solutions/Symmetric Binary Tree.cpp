/*

Method 1 : Using recursion                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely
unbalanced tree, to keep a recursion stack.

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


/*

Method 2 : Using Iteration                          Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(N). We are using a helper queue which will have size of (2 * max child at any node).

*/

class Solution {
public:

    bool mirrorHelper(TreeNode* root1, TreeNode* root2) {

        queue<TreeNode*>helper;

        helper.push(root1);
        helper.push(root2);

        while (!helper.empty()) {

            TreeNode* leftTree = helper.front();
            helper.pop();

            TreeNode* rightTree = helper.front();
            helper.pop();

            if (leftTree == NULL && rightTree == NULL) {
                continue;
            }

            if ((leftTree != NULL && rightTree == NULL) || (leftTree == NULL && rightTree != NULL) || (leftTree -> val != rightTree -> val)) {
                return false;
            }

            helper.push(leftTree -> left);
            helper.push(rightTree -> right);
            helper.push(leftTree -> right);
            helper.push(rightTree -> left);
        }

        return true;
    }

    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;

        return mirrorHelper(root -> left, root -> right);
    }
};