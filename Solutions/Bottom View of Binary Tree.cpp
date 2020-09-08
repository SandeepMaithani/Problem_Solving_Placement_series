/*

Method 1: using Unordered Map                                 Verdict : Accepted

Time Complexity : O(N).

where N is the number of nodes in the given binary tree with each insertion operation in Unordered Map requiring O(1) Time complexity.

Space Complexity : O(N). We are using queue for Traversal.

*/

void topView(struct Node *root)
{
    if (root == NULL) return;

    unordered_map<int, int>hashmap;
    queue<pair<Node*, int>>helper;
    int minLvl = 0, maxLvl = 0;

    helper.push({root, 0});

    while (!helper.empty()) {
        Node* node = helper.front().first;
        int level = helper.front().second;
        helper.pop();

        if (level > maxLvl) {
            maxLvl = level;
        }
        else if (level < minLvl) {
            minLvl = level;
        }

        hashmap[level] = node -> data;

        if (node -> left) {
            helper.push({node -> left, level - 1});
        }

        if (node -> right) {
            helper.push({node -> right, level + 1});
        }
    }

    for (int i = minLvl; i <= maxLvl; i++) {
        cout << hashmap[i] << " ";
    }
}



/*

Method 2: using Map                                  Verdict : Accepted

Time Complexity : O(N*log(N)).

where N is the number of nodes in the given binary tree with each insertion operation in Map requiring O(log(N)) complexity.

Space Complexity : O(N). We are using queue for Traversal.

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

        hashmap[node.second] = node.first -> data;

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