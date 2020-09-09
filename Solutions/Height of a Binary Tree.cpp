/*

Complexity Analysis :

Time Complexity: O(N). where N is number of nodes in the binary tree.

Space Complexity: O(1). We are not using any extra space if function call stack is not concerned.

*/

int height(Node* root)
{
	if (root == NULL) return 0;

	int left = height(root -> left);
	int right = height(root -> right);

	return max(left, right) + 1;
}