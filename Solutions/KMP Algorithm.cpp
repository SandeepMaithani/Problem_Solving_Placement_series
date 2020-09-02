#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;

void prefixString(string &str, vector<int>&prefixKeeper) {
	int cmpInd = 0, i = 1;
	prefixKeeper[0] = 0;

	while (i < str.length()) {
		if (str[i] == str[cmpInd]) {
			prefixKeeper[i] = cmpInd + 1;
			i++;
			cmpInd++;
		}
		else {
			if (cmpInd == 0) {
				prefixKeeper[i] = 0;
				i++;
			}
			else {
				cmpInd = prefixKeeper[cmpInd - 1];
			}
		}
	}
}

int KMPSearch(string &text, string &pattern) {

	vector<int>prefixKeeper(pattern.length());

	prefixString(pattern, prefixKeeper);

	int i = 0, j = 0;

	while (i < text.length() && j < pattern.length()) {

		if (text[i] == pattern[j]) {
			i++;
			j++;
		}
		else {
			if (j == 0) {
				i++;
			}
			else {
				j = prefixKeeper[j - 1];
			}
		}
	}

	if (j == pattern.length()) {
		return i - j;
	}

	return -1;
}

int main() {

	string text, pattern;
	cin >> text >> pattern;

	int answer = KMPSearch(text, pattern);

	cout << answer << endl;

	return 0;
}


