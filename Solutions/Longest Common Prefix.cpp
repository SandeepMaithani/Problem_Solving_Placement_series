/*

Method 1 : Horizontal scanning                      Verdict : Accepted

Complexity Analysis :-

Time complexity : O(S), where S is the sum of all characters in all strings.

In the worst case all N strings are the same. The algorithm compares the string S1 with the other strings, There are S character comparisons, where S is the sum of all characters in the input array.

Space complexity : O(1). We only used constant extra space.

*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) {
            return "";
        }

        string result = strs[0];

        for (int i = 1; i < strs.size(); i++) {

            string wordCheck = strs[i];
            int j = 0;

            while (j < wordCheck.length() && j < result.length() && wordCheck[j] == result[j]) {
                j++;
            }

            if (j == 0) {
                return "";
            }

            if (j < result.length()) {
                result = result.substr(0, j);
            }
        }

        return result;

    }
};



/*

Method 2 : Sort and comparing first and last                  Verdict : Accepted

Complexity Analysis :-

Time complexity : O(N*Log(N)), where N no of string given.

We use sort function to sort all string and then compare last and first string.

Space complexity : O(1). We only used constant extra space.

*/


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result = "";

        if (strs.size() == 0) {
            return "";
        }

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs[strs.size() - 1];

        int i = 0;

        while (i < first.length() && i < last.length() && first[i] == last[i]) {
            result += first[i];
            i++;
        }

        return result;
    }
};