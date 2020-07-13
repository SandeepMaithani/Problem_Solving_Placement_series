/*

METHOD : Sorting and placing at far         Verdict : Accepted

Complexity Analysis :

Time Complexity: O(n*n + n*log(n)) = O(n*n) checking for each job and linearly finding its position to place in far most position.

Space Complexity: O(1).

*/

#include <bits/stdc++.h>
using namespace std;

struct job {
	int id;
	int deadline;
	int profit;
};

bool cmp(job first, job second) {
	return first.profit > second.profit;
}

int main() {


	int n;
	cin >> n;

	int max_limit = INT_MIN;
	int max_profit = 0;
	int job_done = 0;

	vector<job>order(n);

	for (int i = 0; i < n; i++) {
		cin >> order[i].id >> order[i].deadline >> order[i].profit;
		if (order[i].deadline > max_limit) {
			max_limit = order[i].deadline;
		}
	}

	vector<bool>chart(max_limit, false);

	sort(order.begin(), order.end(), cmp);

	for (int i = 0; i < n; i++) {

		for (int j = order[i].deadline - 1; j >= 0; j--) {

			if (chart[j] == false) {
				max_profit += order[i].profit;
				job_done++;
				chart[j] = true;
				break;
			}
		}
	}

	cout << job_done << " " << max_profit << endl;

	return 0;
}