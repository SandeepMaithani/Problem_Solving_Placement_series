/*

Method : Using Min Heap                               Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once heap take log(K) time to push to O(N*log(K)).

Space Complexity: O(K). K size heap used.

*/



#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int k, n;
		cin >> k >> n;

		priority_queue<int, vector<int>, greater<int>>minHeap;

		for (int i = 0; i < n; i++) {
			int value;
			cin >> value;

			minHeap.push(value);

			if (minHeap.size() > k) {
				minHeap.pop();
			}

			if (minHeap.size() == k) {
				cout << minHeap.top() << " ";
			}
			else {
				cout << "-1 ";
			}
		}
		cout << endl;
	}

	return 0;
}