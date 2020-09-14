/*

Method 1 : Using recursion                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since each node is visited at most twice.

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.

*/

/*

Method 2 : Using BFS traversal                        Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since each node is visited only once.

Space complexity : O(N), where N is a number of nodes in the tree.

*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) {
            return root;
        }

        queue<Node*>helper;
        helper.push(root);

        while (!helper.empty()) {
            int size = helper.size();

            for (int i = 0; i < size; i++) {
                Node* node = helper.front();
                helper.pop();

                if (i == size - 1) {
                    node -> next = NULL;
                }
                else {
                    node -> next = helper.front();
                }

                if (node -> left) {
                    helper.push(node -> left);
                }
                if (node -> right) {
                    helper.push(node -> right);
                }
            }
        }

        return root;
    }
};