/*

Method 1 : Using Inorder traversal elements and 2 sum                         Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N), where N is the number of nodes in the BST. And Two check if sum exist or not we will use two pointer technique so it take O(N + N) time.

Space Complexity: O(N). To to store elements during inorder traversal.

*/


class Solution {
public:
    void inorder(TreeNode* root, vector<int>&elements) {
        if (root == NULL) {
            return;
        }

        inorder(root ->left, elements);
        elements.push_back(root -> val);
        inorder(root -> right, elements);
    }

    bool findTarget(TreeNode* root, int k) {
        vector<int>elements;

        inorder(root, elements);

        int left = 0;
        int right = elements.size() - 1;

        while (left < right) {
            if (elements[left] + elements[right] > k) {
                right--;
            }
            else if (elements[left] + elements[right] < k) {
                left++;
            }
            else {
                return true;
            }
        }

        return false;
    }
};




/*

Method 2 : Using Inorder traversal and check compliment                         Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N*Log(N)), where N is the number of nodes in the BST. In the worst case we might be visiting all the nodes of the BST and for each nodes we are looking whether its compliment exist in BST or not which will take Log(N) time so total (N*Log(N)).

Space Complexity: O(N). This is because the maximum amount of space utilized by the recursion stack would be N since the height of a skewed BST could be N.

*/

bool findHelper(struct Node *root, int key) {

    if (root == NULL) {
        return false;
    }

    if (root -> data == key) {
        return true;
    }

    if (key < root -> data) {
        return findHelper(root -> left, key);
    }

    if (key > root -> data) {
        return findHelper(root ->right, key);
    }

}

void inorder(struct Node *root, struct Node *topNode, int &target, int &answer) {
    if (root == NULL || answer) {
        return;
    }

    inorder(root -> left, topNode, target, answer);

    int comp = target - root -> data;
    if (comp > root -> data && findHelper(topNode, comp)) {
        answer = 1;
        return;
    }

    inorder(root -> right, topNode, target, answer);
}

int isPairPresent(struct Node *root, int target)
{
    int answer = false;

    inorder(root, root, target, answer);

    return answer;

}