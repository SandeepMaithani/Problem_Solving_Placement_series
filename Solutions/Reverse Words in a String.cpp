/*

Method 1 : extracting each word               Verdict: Accepted

Complexity Analysis :

Time Complexity: O(N). All operation take constant time so time complexity will be O(1).

Space Complexity: O(N). Since we need a extra string for output we are not doing this inplace.

*/


class Solution {
public:
    string reverseWords(string s) {

        string solution = "";

        for (int i = 0; i < s.length();) {

            while (i < s.length() && s[i] == ' ') {
                i++;
            }

            if (i >= s.length()) return solution;

            int j = i + 1;

            while (j < s.length() && s[j] != ' ') {
                j++;
            }

            if (solution.length() == 0) {
                solution = s.substr(i, j - i) + solution;
            }
            else {
                solution = s.substr(i, j - i) + " " + solution;
            }

            i = j + 1;
        }

        return solution;

    }
};