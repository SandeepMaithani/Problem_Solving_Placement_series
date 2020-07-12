/*

Complexity Analysis :

Time Complexity: O(n*log(n)) Time for sorting.

Space Complexity: O(n) Extra space for vector of pair.

*/

#include <bits/stdc++.h>
using namespace std;

bool endsort(pair<int, int>temp1, pair<int, int>temp2) {
	if (temp1.second < temp2.second) {
		return true;
	}
	return false;
}

int main() {

	int n;
	cin >> n;

	if (n == 0) {
		cout << "0" << endl;
		return 0;
	}

	int count = 1;

	vector<int>start(n);
	vector<int>end(n);
	vector<pair<int, int>>meeting;

	for (int i = 0; i < n; i++) {
		cin >> start[i];
	}

	for (int i = 0; i < n; i++) {
		cin >> end[i];
	}

	for (int i = 0; i < n; i++) {
		meeting.push_back(make_pair(start[i], end[i]));
	}

	sort(meeting.begin(), meeting.end(), endsort);

	int i = 0;

	for (int j = 1; j < meeting.size(); j++) {

		if (meeting[i].second <= meeting[j].first) {
			count++;
			i = j;
		}
	}

	cout << count << endl;

	return 0;
}