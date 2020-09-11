/*

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.

*/


/*

Key Idea :-

For each node there can be four ways that the max path goes through the node:
1. Node only
2. Max path through Left Child + Node
3. Max path through Right Child + Node
4. Max path through Left Child + Node + Max path through Right Child

The idea is to keep trace of four paths and pick up the max one in the end. An important thing to note is, root of every subtree need to return maximum path sum such that at most one child of root is involved.

*/


class Solution {
public:
    int pathSumHelper(TreeNode* root, int &maxSum) {
        if (root == NULL) {
            return 0;
        }

        int leftPart = pathSumHelper(root -> left, maxSum);
        int rightPart = pathSumHelper(root -> right, maxSum);

        int tempValue = max(root -> val, max(leftPart, rightPart) + root -> val);
        int isAnswer = max(tempValue, leftPart + rightPart + root -> val);

        maxSum = max(maxSum, isAnswer);

        return tempValue;
    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;

        int rootSum = pathSumHelper(root, maxSum);

        return maxSum;

    }
};