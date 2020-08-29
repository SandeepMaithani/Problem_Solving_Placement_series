/*

Method 1 : By spliting from middle                Verdict: Accepted

Complexity Analysis:

Time complexity: O(n^2). where n is the length of input string.

Nested traversal of the string is needed. So time complexity is O(n^2).

Space complexity: O(1).

No extra space is needed.

*/


class Solution {
public:
    void splitAtMidle(string &s, int left, int right, int &maxLen, int &st) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }

        int tempLen = right - left - 1;

        if (tempLen > maxLen) {
            maxLen = tempLen;
            st = left + 1;
        }
    }

    string longestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        int maxLen = 1;
        int st = 0;

        for (int i = 0; i < s.length() - 1; i++) {
            splitAtMidle(s, i, i, maxLen, st);
            splitAtMidle(s, i, i + 1, maxLen, st);
        }

        return s.substr(st, maxLen);
    }
};


/*

Method 2 : Brute Force                Verdict: TLE

Complexity Analysis:

Time complexity: O(n^3). where n is the length of input string.

O(N^2) time is required to generate all substring and extra O(N) time is required to to check each substring so O(N^3).

Space complexity: O(1).

No extra space is needed.

*/

/*

Idea here is to generate all the substring and check then check wheather the string is palindrome or not if it is then weather it is max length palindrome of not.

*/