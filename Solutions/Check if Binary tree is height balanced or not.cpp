/*

Complexity Analysis :

Time Complexity: O(N). where N is number of nodes in the binary tree.

Space Complexity: O(1). We are not using any extra space if function call stack is not concerned.

*/


class Solution {
public:
    int height(TreeNode* root, bool &isHeightBalanced) {
        if (root == NULL) {
            return 0;
        }

        int left = height(root -> left, isHeightBalanced);
        int right = height(root -> right, isHeightBalanced);

        if (abs(left - right) > 1) {
            isHeightBalanced = false;
        }

        return 1 + max(left, right);
    }

    bool isBalanced(TreeNode* root) {

        bool isHeightBalanced = true;

        int temp = height(root, isHeightBalanced);

        return isHeightBalanced;

    }
};