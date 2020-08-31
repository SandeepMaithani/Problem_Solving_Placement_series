/*

Analysis of the Algorithm :-

The average and best case running time of the Rabin-Karp algorithm is O(n+m), but its worst-case time is O(nm).
Worst case of Rabin-Karp algorithm occurs when all characters of pattern and text are same as the hash values of all the substrings of txt[] match with hash value of pat[].
For example pat[] = “AAA” and txt[] = “AAAAAAA”.

*/


#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define endl "\n"
typedef long long int lli;
typedef long long ll;


const int prime = 3;

ll createHashValue(string &str, int n) {
	ll result = 0;

	for (int i = 0; i < n; i++) {
		result += (ll)(str[i] * (ll)pow(prime, i));
	}

	return result;
}

ll rollingHashValue(string &str, int oldIndex, int newIndex, ll oldHash, int patLength) {
	ll newHash = oldHash - str[oldIndex];
	newHash /= prime;
	newHash += (ll)(str[newIndex] * (ll)(pow(prime, patLength - 1)));

	return newHash;
}

bool checkEqual(string &text, string &pattern, int startText, int endText, int startPattern, int endPattern) {
	if (endText - startText != endPattern - startPattern) {
		return false;
	}

	while (startText <= endText && startPattern <= endPattern) {
		if (text[startText] != pattern[startPattern]) {
			return false;
		}
		startText++;
		startPattern++;
	}
	return true;
}


int main() {

	string text, pattern;
	cin >> text >> pattern;

	bool flag = true;

	ll patHash = createHashValue(pattern, pattern.length());
	ll strHash = createHashValue(text, pattern.length());

	for (int i = 0; i <= text.length() - pattern.length(); i++) {
		if (patHash == strHash && checkEqual(text, pattern, i, i + pattern.length() - 1, 0, pattern.length() - 1)) {
			cout << i << endl;
			flag = false;
		}
		else if (i < text.length() - pattern.length()) {
			strHash = rollingHashValue(text, i, i + pattern.length(), strHash, pattern.length());
		}
	}

	if (flag) {
		cout << "Not Found" << endl;
	}

	return 0;
}


