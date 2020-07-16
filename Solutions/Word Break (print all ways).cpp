/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(2^n).

In each call you are calling the recursive function with length 1,2....n(in worst case).

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

void construct(string str, unordered_set<string>&dictionary, string sentence, int n) {
	for (int len = 1; len <= n; len++) {
		string prefix = str.substr(0, len);

		if (dictionary.find(prefix) != dictionary.end()) {
			if (len == n) {
				sentence += prefix;
				cout << sentence << endl;
				return;
			}
			sentence += prefix + " ";
			construct(str.substr(len, n - len), dictionary, sentence, n - len);
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);




	unordered_set<string>dictionary;

	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		dictionary.insert(temp);
	}

	string str, sentence = "";
	cin >> str;

	construct(str, dictionary, sentence, str.length());

	return 0;
}