/*

Complexity Analysis :

Time Complexity: O(n*log(n)) Time for sorting.

Space Complexity: O(n) Extra space for vector of structure.

*/

#include <bits/stdc++.h>
using namespace std;

struct item {
	int value, weight;
	double ratio;
};

bool comp(item first, item second) {
	return first.ratio > second.ratio;
}

int main() {

	int n, w;
	cin >> n >> w;

	int fill = 0;
	double profit = 0.0;

	vector<item>lists(n);

	for (int i = 0; i < n; i++) {

		cin >> lists[i].value;
		cin >> lists[i].weight;
		lists[i].ratio = (double)lists[i].value / lists[i].weight;
	}

	sort(lists.begin(), lists.end(), comp);

	for (int i = 0; i < n; i++) {

		if (fill + lists[i].weight <= w) {
			fill += lists[i].weight;
			profit += lists[i].value;
		}
		else {
			int left = w - fill;
			profit += (double)left * (lists[i].ratio);
			break;
		}
	}

	printf("%.2f\n", profit);

	return 0;
}