/*

Method 1: Using Recusrion                              Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). Where N is total number of nodes in the tree.

Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(n).

*/

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);

    cout << root -> data << " ";
}



/*

Method 2 : Iterative way                                     Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). Where N is total number of nodes in the tree.

Space Complexity: O(N + N). where N is the total number of nodes in the tree and we ahve used two stack here.

*/

public:
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>solution;
    stack<TreeNode*>st1, st2;

    if (root == NULL) return solution;

    st1.push(root);

    while (!st1.empty()) {
        TreeNode* node = st1.top();
        st1.pop();
        st2.push(node);

        if (node -> left) {
            st1.push(node -> left);
        }
        if (node -> right) {
            st1.push(node -> right);
        }
    }

    while (!st2.empty()) {
        solution.push_back(st2.top() -> val);
        st2.pop();
    }
    return solution;
};