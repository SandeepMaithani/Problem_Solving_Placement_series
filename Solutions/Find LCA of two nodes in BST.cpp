/*

Method 1 : Using BST Property and Iteration                          Verdict : Accepted

Complexity Analysis

Time Complexity : O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity : O(1). We are not using any extra space.

*/

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* helper = root;

        while (helper != NULL) {
            if (p -> val < helper -> val && q -> val < helper -> val) {
                helper = helper -> left;
            }
            else if (p -> val > helper -> val && q -> val > helper -> val) {
                helper = helper -> right;
            }
            else {
                return helper;
            }
        }

        return helper;

    }
};


/*

Method 2 : Using BST Property and recursion                          Verdict : Accepted

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        if (root == NULL) {
            return NULL;
        }

        if (root -> val > p -> val && root -> val > q -> val)
            return lowestCommonAncestor(root->left, p, q);

        if (root -> val < p -> val && root -> val < q -> val)
            return lowestCommonAncestor(root->right, p, q);

        return root;

    }
};



/*

Method 3 : Using Binary Tree LCA Method                               Verdict : Accepted

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