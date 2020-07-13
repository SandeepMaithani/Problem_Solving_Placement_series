/*

METHOD : Sorting          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(n + n*log(n)) = O(n*log(n)) Time taken by sort function.

Space Complexity: O(1).

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		int platform = 0;
		int local = 0;

		vector<int>arr(n);
		vector<int>dprt(n);

		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> dprt[i];
		}

		sort(arr.begin(), arr.end());
		sort(dprt.begin(), dprt.end());

		int i = 0;
		int max_req = 1;
		int curr_req = 1;

		for (int j = 1; j < n;) {
			if (arr[j] < dprt[i]) {
				curr_req++;
				j++;
			}
			else if (dprt[i] == arr[j]) {        //This Condition is question dependent you can skip depend on question.
				curr_req++;
				j++;
			}
			else {
				curr_req--;
				i++;
			}

			if (max_req < curr_req) {
				max_req = curr_req;
			}
		}

		cout << max_req << endl;
	}

	return 0;
}