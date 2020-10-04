
/*

Method 1 : using merge process of merge sort                     verdict: Accepted

Complexity Analysis :

Time Complexity: O(N*M), Where N is the number of linked list and M is the maximum number of nodes in linked list.

Space Complexity: O(1), We don't need any extra space .

*/


Node* mergeList(Node* l1, Node* l2) {
	if (!l1) {
		return l2;
	}
	else if (!l2) {
		return l1;
	}
	else if (l1 -> data <= l2 -> data) {
		l1 -> bottom = mergeList(l1 -> bottom, l2);
		return l1;
	}
	else {
		l2 -> bottom = mergeList(l1, l2 -> bottom);
		return l2;
	}
}


Node *flatten(Node *root)
{
	// Your code here

	if (root == NULL || root -> next == NULL) {
		return root;
	}

	root -> next = flatten(root -> next);
	root = mergeList(root, root -> next);

	return root;
}




/*

Method 2 : storing all nodes value and then sorting                     verdict: Accepted

Complexity Analysis :

Time Complexity: O(N*Log(N)), where N is the number of nodes in the linked list, and sort function take N*log(N) time to sort the elements.

Space Complexity: O(N), Since we are using a vector to store all the node data.

*/


Node *flatten(Node *root)
{
	if (root == NULL) {
		return root;
	}

	vector<int>listData;
	Node *helper = root;

	while (helper != NULL) {
		Node *temp = helper -> bottom;
		listData.push_back(helper -> data);

		while (temp != NULL) {
			listData.push_back(temp -> data);
			temp = temp -> bottom;
		}

		helper = helper -> next;
	}

	sort(listData.begin(), listData.end());

	Node *dummy = new Node(0);
	Node *dummyHelper = dummy;

	for (auto it : listData) {
		Node *newNode = new Node(it);
		dummyHelper -> bottom = newNode;
		dummyHelper = newNode;
	}

	return dummy -> bottom;
}