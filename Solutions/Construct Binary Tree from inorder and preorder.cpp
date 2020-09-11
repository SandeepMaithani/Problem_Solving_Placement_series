/*

Method 1 : Using Unordered Map                                Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once and look up time of the unordered Map is Average case O(1).

Space complexity : O(N). Aince we are using map to store all the value to decrease the look up time.

*/


class Solution {
public:
    TreeNode* buildHelper(vector<int>& preorder, int &start, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>&hashmap) {
        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[start]);
        int rootPos = hashmap[preorder[start]];
        start++;

        root -> left = buildHelper(preorder, start, inorder, inStart, rootPos - 1, hashmap);
        root -> right = buildHelper(preorder, start, inorder, rootPos + 1, inEnd, hashmap);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0, inStart = 0, inEnd = inorder.size() - 1;
        unordered_map<int, int>hashmap;

        for (int i = 0; i < inorder.size(); i++) {
            hashmap[inorder[i]] = i;
        }

        return buildHelper(preorder, start, inorder, 0, inorder.size() - 1, hashmap);
    }
};


/*

Method 2 : Using Linear search                               Verdict : Accepted

Complexity Analysis :

Time complexity : O(N * N), where N is a number of nodes in the tree, since at each node we are doing a linear search in inorder vector which cost O(N) so total it will cost O(N*N).

Space complexity : O(log(N)) in the best case of completely balanced tree and O(N) in the worst case of completely unbalanced tree, to keep a recursion stack.

*/

class Solution {
public:
    TreeNode* buildHelper(vector<int>& preorder, int &start, vector<int>& inorder, int inStart, int inEnd) {
        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[start]);
        int rootPos = find(inorder.begin(), inorder.end(), preorder[start]) - inorder.begin();
        start++;

        root -> left = buildHelper(preorder, start, inorder, inStart, rootPos - 1);
        root -> right = buildHelper(preorder, start, inorder, rootPos + 1, inEnd);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start = 0, inStart = 0, inEnd = inorder.size() - 1;

        return buildHelper(preorder, start, inorder, 0, inorder.size() - 1);


    }
};