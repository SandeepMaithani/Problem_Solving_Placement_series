/*

Method 1 : Using Unordered Map                                Verdict : Accepted

Complexity Analysis :

Time complexity : O(N), where N is a number of nodes in the tree, since one visits each node exactly once and look up time of the unordered Map is Average case O(1).

Space complexity : O(N). Aince we are using map to store all the value to decrease the look up time.

*/


class Solution {
public:

    TreeNode* buildHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int &curRoot, unordered_map<int, int> &hashmap) {

        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[curRoot]);
        int pos = hashmap[postorder[curRoot]];
        curRoot--;

        root -> right = buildHelper(inorder, pos + 1, inEnd, postorder, curRoot, hashmap);
        root -> left = buildHelper(inorder, inStart, pos - 1, postorder, curRoot, hashmap);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int curRoot = postorder.size() - 1;

        unordered_map<int, int>hashmap;

        for (int i = 0; i < inorder.size(); i++) {
            hashmap[inorder[i]] = i;
        }

        return buildHelper(inorder, 0, inorder.size() - 1, postorder, curRoot, hashmap);

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

    TreeNode* buildHelper(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int &curRoot) {

        if (inStart > inEnd) {
            return NULL;
        }

        TreeNode* root = new TreeNode(postorder[curRoot]);
        int pos = find(inorder.begin(), inorder.end(), postorder[curRoot]) - inorder.begin();
        curRoot--;

        root -> right = buildHelper(inorder, pos + 1, inEnd, postorder, curRoot);
        root -> left = buildHelper(inorder, inStart, pos - 1, postorder, curRoot);

        return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int curRoot = postorder.size() - 1;

        return buildHelper(inorder, 0, inorder.size() - 1, postorder, curRoot);

    }
};