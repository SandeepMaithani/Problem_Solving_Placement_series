/*

Using Backtracking        Verdict : Accepted
Hackerearth solution

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

bool solution = false;

bool noattack(vector<vector<int>>&board, int i, int j, int n) {

	for (int row = 0; row < i; row++) {
		if (board[row][j]) {
			return false;
		}
	}

	int row = i;
	int col = j;

	while (row >= 0 && col >= 0) {
		if (board[row][col]) {
			return false;
		}
		row--;
		col--;
	}

	row = i;
	col = j;

	while (row >= 0 && col < n) {
		if (board[row][col]) {
			return false;
		}
		row--;
		col++;
	}

	return true;
}

bool placequeen(vector<vector<int>>&board, int i, int n) {

	if (i == n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << board[i][j] << " ";
			}
			cout << endl;
		}

		solution = true;

		return true;
	}

	for (int j = 0; j < n; j++) {
		if (noattack(board, i, j, n)) {

			board[i][j] = true;
			bool nextpossible = placequeen(board, i + 1, n);

			if (nextpossible) {
				return true;
			}

			board[i][j] = false;
		}
	}
	return false;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	vector<vector<int>>board(n, vector<int>(n, false));

	placequeen(board, 0, n);

	if (!solution) {
		cout << "Not possible" << endl;
	}

	return 0;
}


/*

Using Backtracking            Vecdict : Accepted
Geeks for Geeks solution

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;

bool solution = false;

bool noattack(vector<vector<int>>&board, int i, int j, int n) {

	for (int row = 0; row < i; row++) {
		if (board[row][j]) {
			return false;
		}
	}

	int row = i;
	int col = j;

	while (row >= 0 && col >= 0) {
		if (board[row][col]) {
			return false;
		}
		row--;
		col--;
	}

	row = i;
	col = j;

	while (row >= 0 && col < n) {
		if (board[row][col]) {
			return false;
		}
		row--;
		col++;
	}

	return true;
}

bool placequeen(vector<vector<int>>&board, vector<vector<int>>&queenpos, int i, int n) {

	if (i == n) {

		vector<int>pos;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j]) {
					pos.push_back(j + 1);
				};
			}
		}

		queenpos.push_back(pos);

		return false;
	}

	for (int j = 0; j < n; j++) {
		if (noattack(board, i, j, n)) {

			board[i][j] = true;
			bool nextpossible = placequeen(board, queenpos, i + 1, n);

			if (nextpossible) {
				return true;
			}

			board[i][j] = false;
		}
	}
	return false;
}

int main() {

	int t;
	cin >> t;

	while (t--) {

		int n;
		cin >> n;

		vector<vector<int>>board(n, vector<int>(n, false));
		vector<vector<int>>queenpos;

		placequeen(board, queenpos, 0, n);
		sort(queenpos.begin(), queenpos.end());

		if (queenpos.size() == 0) {
			cout << "-1";
		}
		else {
			for (int i = 0; i < queenpos.size(); i++) {
				cout << "[";
				for (int j = 0; j < queenpos[i].size(); j++) {
					cout << queenpos[i][j] << " ";
				}
				cout << "] ";
			}
		}
		cout << "\n";
	}
	return 0;
}