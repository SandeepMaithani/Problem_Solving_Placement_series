/*

Method 1 : Using Level order traversal                   Verdict : Accepted

Time Complexity: O(N), Where N is no of nodes in the tree.

Since we are traversing each and every node, so the complexity is O(N).

Space Complexity: O(Maximum no of child at any level).

Since we are using queue to store node at each level.

*/

void leftView(Node *root)
{
  if (root == NULL) return;

  queue<Node*>helper;
  helper.push(root);

  while (!helper.empty()) {
    int size = helper.size();

    cout << helper.front() -> data << " ";

    for (int i = 0; i < size; i++) {
      Node* node = helper.front();
      helper.pop();

      if (node -> left) helper.push(node -> left);
      if (node -> right) helper.push(node -> right);
    }
  }
}


/*

Method 2 : Using Recursive Aproach                         Verdict : Accepted

Time Complexity: O(N), The function does a simple traversal of the tree, so the complexity is O(N).

Space Complexity: O(N), due to the stack space during recursive call.

*/

void viewHelper(Node *root, int level, int &maxLevel) {
  if (root == NULL) {
    return;
  }

  if (maxLevel < level) {
    cout << root -> data << " ";
    maxLevel = level;
  }

  viewHelper(root -> left, level + 1, maxLevel);
  viewHelper(root -> right, level + 1, maxLevel);
}

void leftView(Node *root)
{
  if (root == NULL) return;

  int maxLevel = 0;

  viewHelper(root, 1, maxLevel);

}