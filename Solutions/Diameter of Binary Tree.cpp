/*

Complexity Analysis :

Time Complexity: O(N). where N is number of nodes in the binary tree.

Space Complexity: O(1). We are not using any extra space if function call stack is not concerned.

*/



class Solution {
public:

    int caldia(TreeNode* node, int &answer) {

        if (node == NULL) {
            return 0;
        }

        int left = caldia(node -> left, answer);
        int right = caldia(node -> right, answer);

        int localDia = left + right + 1;
        int height = max(left, right) + 1;

        answer = max(answer, localDia);

        return height;
    }

    int diameterOfBinaryTree(TreeNode* root) {

        if (root == NULL) {
            return 0;
        }

        int answer = 0;

        int temp = caldia(root, answer);

        return (answer - 1);

    }
};