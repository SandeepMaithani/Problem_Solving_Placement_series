/*

Method 1 : Using BST Property and Iteration                          Verdict : Accepted

Complexity Analysis

Time Complexity : O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity : O(1). We are not using any extra space.

*/

void getFloorCeil(TreeNode* root, TreeNode* &floor, TreeNode* &ceil, int key) {
	if (root == NULL) {
		return;
	}

	while (root) {
		if (key < root -> val) {
			ceil = root;
			root = root -> left;
		}
		else if (key > root -> val) {
			floor = root;
			root = root -> right;
		}
		else {
			floor = ceil = root;
			return;
		}
	}
}

/*

Method 2 : Using BST Property and recursion                          Verdict : Accepted

Complexity Analysis

Time Complexity: O(N), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST.

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

void getFloorCeil(TreeNode* root, TreeNode* &floor, TreeNode* &ceil, int key) {
	if (root == NULL) {
		return;
	}

	if (key < root -> val) {

		ceil = root;
		getFloorCeil(root -> left, floor, ceil, key);
	}
	else if (key > root -> val) {

		floor = root;
		getFloorCeil(root -> right, floor, ceil, key);
	}
	else {

		floor = ceil = root;
		return;
	}
}