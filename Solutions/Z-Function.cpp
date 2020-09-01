/*

Analysis of the Algorithm :-

Application of the Z Algorithm is for the standard string matching problem of finding matches for a pattern T of length m in a string S of length n.
This can be done in O(n + m) time by using the Z Algorithm on the string T$S (that is, concatenating T, $ and S) where $ is any character that matches nothing or will not be a part of string .
The indices i with Z[i] = m correspond to matches of T in S.

Space Complexity :- O(n + m)

*/

#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int ll;


vector<ll> zAlgo(string str) {
	ll len = str.length();
	ll l = 0, r = 0;
	vector<ll>z(len);

	for (ll i = 1; i < len; i++) {
		if (i > r) {
			l = r = i;

			while (r < len && str[r] == str[r - l]) {
				r++;
			}

			z[i] = r - l;
			r--;
		}
		else {
			ll ind = i - l;

			if (i + z[ind] <= r) {
				z[i] = z[ind];
			}
			else {
				l = i;

				while (r < len && str[r] == str[r - l]) {
					r++;
				}

				z[i] = r - l;
				r--;
			}
		}
	}

	return z;
}


int main() {

	string text, pattern;
	cin >> text >> pattern;

	string zHelper = pattern + '$' + text;

	vector<ll> zVal = zAlgo(zHelper);

	for (int i = 0; i < zVal.size(); i++) {
		if (zVal[i] == pattern.length()) {
			cout << (i - pattern.length() - 1) << endl;
		}
	}

	return 0;
}


