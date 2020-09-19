/*

Method 1 : Using controlled Recursion and stack                          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. We will be visiting each and every node.

1. next()     :-  would take O(1). We only make such a call for nodes which have a right child. Otherwise, we simply return.Thus, the amortized (average) time complexity for this function would still be O(1).

2. hasNext()  :-  would take O(1).

Space Complexity: O(H). Where H is height of tree, which is occupied by our custom stack for simulating the inorder traversal.

*/


class BSTIterator {
public:
    stack<TreeNode*> helper;

    void leftMostNode(TreeNode* root, stack<TreeNode*> &helper) {
        if (root == NULL) {
            return;
        }

        while (root) {
            helper.push(root);
            root = root -> left;
        }
    }

    BSTIterator(TreeNode* root) {
        leftMostNode(root, helper);
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* next = helper.top();
        helper.pop();

        if (next -> right) {
            leftMostNode(next -> right, helper);
        }

        return next -> val;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !helper.empty();
    }
};



/*

Method 2 : By storing elements using Inorder traversal                          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. We will be visiting each and every node.

1. next()     :-  would take O(1).
2. hasNext()  :-  would take O(1).

Space Complexity: O(N). To to store elements during inorder traversal.

*/

class BSTIterator {
public:
    vector<int>traversal;
    int curr;

    void inOrder(TreeNode* root, vector<int> &traversal) {
        if (root == NULL) {
            return;
        }

        inOrder(root -> left, traversal);
        traversal.push_back(root -> val);
        inOrder(root -> right, traversal);
    }

    BSTIterator(TreeNode* root) {
        inOrder(root, traversal);
        curr = 0;
    }

    /** @return the next smallest number */
    int next() {
        return traversal[curr++];
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return curr < traversal.size();
    }
};
