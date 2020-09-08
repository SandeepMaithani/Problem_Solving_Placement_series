/*

Method 1: using Unordered Map                                 Verdict : Accepted

Time Complexity : O(N).

where N is the number of nodes in the given binary tree with each insertion operation in Unordered Map requiring O(1) Time complexity.

Space Complexity : O(N).

We are using queue for Traversal.

*/


/*

Method 2: using Map                                  Verdict : Accepted

Time Complexity : O(N*log(N)).

where N is the number of nodes in the given binary tree with each insertion operation in Map requiring O(log(N)) complexity.

Space Complexity : O(N).

We are using queue for Traversal.

*/

void topView(struct Node *root)
{
    if (root == NULL) return;

    map<int, int>hashmap;
    queue<pair<Node*, int>>helper;

    helper.push({root, 0});

    while (!helper.empty()) {
        pair<Node*, int>node = helper.front();
        helper.pop();

        if (hashmap.count(node.second) == 0) {
            hashmap[node.second] = node.first -> data;
        }

        if (node.first -> left) {
            helper.push({node.first -> left, node.second - 1});
        }

        if (node.first -> right) {
            helper.push({node.first -> right, node.second + 1});
        }
    }

    for (auto it : hashmap) {
        cout << it.second << " ";
    }
}