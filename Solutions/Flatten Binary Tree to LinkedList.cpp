/*

Method 1 : Using recursion                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since each node is visited at most twice.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.

*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        flatten(root -> left);
        flatten(root -> right);

        if (root -> left != NULL) {
            TreeNode * nodeToFlat = root -> left;

            while (nodeToFlat -> right != NULL) {
                nodeToFlat = nodeToFlat -> right;
            }

            nodeToFlat -> right = root -> right;
            root -> right = root -> left;
            root -> left = NULL;
        }
    }
};


/*

Method 2 : Using stack and iterations                        Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since each node is visited only once.

Space complexity : O(2^(log(N)), Here log(N) is minimum tree height with N nodes because when height is minimum tree wil be bulky which results in maximum no nodes at last level.

*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL) {
            return;
        }

        stack<TreeNode*>helper;

        helper.push(root);

        while (!helper.empty()) {
            TreeNode* nodeToFlat = helper.top();
            helper.pop();

            if (nodeToFlat -> right) {
                helper.push(nodeToFlat -> right);
            }
            if (nodeToFlat -> left) {
                helper.push(nodeToFlat -> left);
            }

            if (!helper.empty()) {
                nodeToFlat -> left = NULL;
                nodeToFlat -> right = helper.top();
            }
        }
    }
};