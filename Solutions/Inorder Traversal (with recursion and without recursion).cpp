/*

Method 1: Using Recusrion                              Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). Where N is total number of nodes in the tree.

Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(n).

*/

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    inOrder(root -> left);

    cout << root -> data << " ";

    inOrder(root -> right);

}



/*

Method 2 : Iterative way                                     Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). Where N is total number of nodes in the tree.

Space Complexity: O(N). where N is the total number of nodes in the tree.

*/


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {

        vector<int>solution;
        stack<TreeNode*>st;

        if (root == NULL) return solution;

        while (root || !st.empty()) {

            while (root) {
                st.push(root);
                root = root -> left;
            }

            root = st.top();
            st.pop();

            solution.push_back(root -> val);

            root = root -> right;
        }

        return solution;
    }
};