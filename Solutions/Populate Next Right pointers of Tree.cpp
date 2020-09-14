/*

Method 1 : Using nested loop                         Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since each node is visited at most twice.

Space complexity : O(1), No extra space required.

*/

class Solution {
public:
    Node* getNextNode(Node* root) {
        Node* helper = root -> next;

        while (helper) {
            if (helper -> left) {
                return helper -> left;
            }
            else if (helper -> right) {
                return helper -> right;
            }
            helper = helper -> next;
        }
        return NULL;
    }

    Node* connect(Node* root) {

        if (root == NULL) {
            return root;
        }

        Node* helper = root;

        while (helper) {
            Node* levelHelper = helper;

            while (levelHelper) {
                if (levelHelper -> left) {
                    if (levelHelper -> right) {
                        levelHelper -> left -> next = levelHelper -> right;
                    }
                    else {
                        levelHelper -> left -> next = getNextNode(levelHelper);
                    }
                }

                if (levelHelper -> right) {
                    levelHelper -> right -> next = getNextNode(levelHelper);
                }

                levelHelper = levelHelper -> next;
            }

            if (helper -> left) {
                helper = helper -> left;
            }
            else if (helper -> right) {
                helper = helper -> right;
            }
            else {
                helper = getNextNode(helper);
            }
        }

        return root;
    }
};



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