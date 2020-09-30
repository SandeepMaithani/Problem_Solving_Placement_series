/*

Method 1 : Sliding Window Optimized(Single pass)                           verdict : Accepted

Complexity Analysis:

Time Complexity: O(N). In the worst case each character will be visited only once by the window.

Space complexity : O(min(M, N). We need O(k) space for the sliding window, where k is the size of the Set.
The size of the Set is upper bounded by the size of the string N and the size of the charset/alphabet M.


*/

class Solution {
public:
	int lengthOfLongestSubstring(string text) {
		unordered_map<char, int>hashMap;
		int currLength = 0;
		int length = 0;

		int i = 0;
		int winStart = 0;
		int size = text.length();

		while (i < size && hashMap.find(text[i]) == hashMap.end()) {
			hashMap[text[i]] = i;
			currLength++;
			i++;
		}

		length = currLength;

		while (i < size) {
			if (hashMap.find(text[i]) == hashMap.end() || hashMap[text[i]] < winStart) {
				hashMap[text[i]] = i;
				currLength++;

				if (currLength > length) {
					length = currLength;
				}
			}
			else {
				currLength = i - hashMap[text[i]];
				winStart = hashMap[text[i]] + 1;
				hashMap[text[i]] = i;
			}
			i++;
		}

		return length;
	}
};


/*

Method 2 : Sliding Window and character array(double pass)                         verdict : Accepted

Complexity Analysis:

Time Complexity: O(2*N) = O(N). In the worst case each character will be visited twice by window.

Space Compelxity: O(1), We are using a constent character array of size 26.

*/


void longestSubstring(string text, int &length) {
	vector<bool>words(26, false);
	int currLength = 0;
	int i = 0;
	int size = text.length();

	while (i < size && words[text[i] - 'a'] == false) {
		words[text[i] - 'a'] = true;
		currLength++;
		i++;
	}

	length = currLength;

	while (i < size) {
		if (words[text[i] - 'a'] == false) {
			words[text[i] - 'a'] = true;
			currLength++;

			if (currLength > length) {
				length = currLength;
			}
			i++;
		}
		else {
			words[text[i - currLength] - 'a'] = false;
			currLength--;
		}
	}
}




/*

Method 3 : Brute Force                               verdict : Accepted

Complexity Analysis:

Time Complexity: O(N^3). We will genrate all substring and check for Longest Substring Without Repeating Characters.

Space Compelxity: O(1), No extra space required.

*/
