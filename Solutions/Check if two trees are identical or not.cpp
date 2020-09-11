/*

Method 1 : Using recursion                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.

*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {

        if (p == NULL && q == NULL) {
            return true;
        }
        else if (p != NULL && q != NULL && p -> val == q -> val) {
            if (isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right)) {
                return true;
            }
        }

        return false;

    }
};




/*

Method 2 : Using inorder,postorder and preorder                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(N). We require extra vector to store the inorder,preorder and postorder traversal.

*/


/*

Key idea is to get the DFS traversal(Inorder,preorder and postorder) of each tree and check if all 3 DFS traversal of 1 tree is equal to all 3 DFS traversal of second tree if they are then they are identical else they are not.


/*