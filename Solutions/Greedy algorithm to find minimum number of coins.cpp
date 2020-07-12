/*

Complexity Analysis :

Time Complexity: O(n*log(n)) Time for sorting.

Space Complexity: O(1).

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n, amount, count = 0;

	cin >> n >> amount;

	vector<int>coins(n);

	for (int i = 0; i < n; i++) {
		cin >> coins[i];
	}

	sort(coins.begin(), coins.end(), greater<int>());

	for (int i = 0; i < n && amount; i++) {

		if (amount >= coins[i]) {
			count += amount / coins[i];
			amount = amount % coins[i];
		}

	}

	cout << count << endl;

	return 0;
}


/*

while (amount >= coins[i]) {
	amount -= coins[i];
	count++;
}

*/