/*
Method 1 : Using Two Stack                        Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). where N is no of nodes in the Tree.

Space Complexity: O(N)+(N) = O(N). Two stack used to perform zig zag traversal.

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>solution;

        if (root == NULL) {
            return solution;
        }

        stack<TreeNode*>LR;
        stack<TreeNode*>RL;

        LR.push(root);

        while (!LR.empty() || !RL.empty()) {
            vector<int>helper1;
            while (!LR.empty()) {
                TreeNode* node = LR.top();
                LR.pop();
                helper1.push_back(node -> val);

                if (node -> left) {
                    RL.push(node -> left);
                }
                if (node -> right) {
                    RL.push(node -> right);
                }
            }

            solution.push_back(helper1);

            vector<int>helper2;

            while (!RL.empty()) {
                TreeNode* node = RL.top();
                RL.pop();
                helper2.push_back(node -> val);

                if (node -> right) {
                    LR.push(node -> right);
                }
                if (node -> left) {
                    LR.push(node -> left);
                }
            }

            if (!helper2.empty()) {
                solution.push_back(helper2);
            }
        }
        return solution;
    }
};



/*

Method 2 : Using Deque                        Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N). where N is no of nodes in the Tree.

Space Complexity: O(N). Deque is used to perform zig zag traversal.

*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>solution;

        if (root == NULL) {
            return solution;
        }

        bool direction = true;
        TreeNode* node;

        deque<TreeNode*>helper;
        helper.push_back(root);

        while (!helper.empty()) {
            vector<int>answer;
            int size = helper.size();

            for (int i = 0; i < size; i++) {

                if (direction == true) {
                    node = helper.back();
                    helper.pop_back();
                    answer.push_back(node -> val);

                    if (node -> left) {
                        helper.push_front(node -> left);
                    }
                    if (node -> right) {
                        helper.push_front(node -> right);
                    }
                }
                else {
                    node = helper.front();
                    helper.pop_front();
                    answer.push_back(node -> val);

                    if (node -> right) {
                        helper.push_back(node -> right);
                    }
                    if (node -> left) {
                        helper.push_back(node -> left);
                    }
                }
            }
            direction = !direction;
            solution.push_back(answer);
        }

        return solution;
    }
};