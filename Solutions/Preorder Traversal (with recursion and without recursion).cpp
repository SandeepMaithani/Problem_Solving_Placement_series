/*

Method 1: Using Recusrion                              Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). Where N is total number of nodes in the tree.

Auxiliary Space : If we don’t consider size of stack for function calls then O(1) otherwise O(n).

*/

void preorder(Node* root) {
	if (root == NULL) {
		return;
	}

	cout << root -> data << " ";

	preorder(root -> left);
	preorder(root -> right);

}




/*

Method 2 : Iterative way                                     Verdict : Accepted


Time Complexity: O(N). Where N is total number of nodes in the tree.

Space Complexity: O(N). where N is the total number of nodes in the tree.

*/


class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {

		stack<TreeNode*>st;
		vector<int>solution;

		if (root == NULL) return solution;

		st.push(root);

		while (!st.empty()) {
			TreeNode* node = st.top();
			st.pop();

			solution.push_back(node -> val);

			if (node -> right) {
				st.push(node -> right);
			}

			if (node -> left) {
				st.push(node -> left);
			}
		}

		return solution;
	}
};