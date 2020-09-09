/*

Complexity Analysis :

Time Complexity: O(N). where N is number of nodes in the binary tree.

Space Complexity: O(N). We are using a helper queue for level order traversal.

*/


class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>solution;

        if (root == NULL) return solution;

        queue<TreeNode*>helper;

        helper.push(root);

        while (!helper.empty()) {
            int size = helper.size();
            vector<int>answer;

            TreeNode* node = helper.front();

            for (int i = 0; i < size; i++) {
                node = helper.front();
                helper.pop();
                answer.push_back(node -> val);

                if (node -> left) {
                    helper.push(node -> left);
                }
                if (node -> right) {
                    helper.push(node -> right);
                }
            }
            solution.push_back(answer);
        }
        return solution;
    }
};