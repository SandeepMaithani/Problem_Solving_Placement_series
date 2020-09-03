/*

Method 1 :- Using KMP PrefixSubstring array                         Verdict :- Accepted

Complexity analysis

Time complexity: O(N).

The algorithm is linear with maximum (2 * n) * 2 iterations.

Space complexity: O(N).

Additional space for the reverse string and the concatenated string.

*/

class Solution {
public:
    int prefixSub(string &str) {
        int len = 0;
        int i = 1;

        vector<int>lenKeeper(str.length());

        lenKeeper[0] = 0;

        while (i < str.length()) {
            if (str[i] == str[len]) {
                lenKeeper[i] = len + 1;
                len++;
                i++;
            }
            else {
                if (len == 0) {
                    lenKeeper[i] = 0;
                    i++;
                }
                else {
                    len = lenKeeper[len - 1];
                }
            }
        }

        return lenKeeper[lenKeeper.size() - 1];
    }

    string shortestPalindrome(string s) {

        if (s.length() <= 1) {
            return s;
        }

        string rev(s);
        reverse(rev.begin(), rev.end());

        string temp = s + "$" + rev;

        int len = prefixSub(temp);

        string toAdd = rev.substr(0, rev.length() - len);

        string solution = toAdd + s;

        return solution;

    }
};


/*

Method 2 :- Brute Force                           Verdict :- TLE

Complexity Analysis

Time complexity: O(n^2).

We iterate over the entire length of string s.
In each iteration, we compare the substrings which is linear in size of substrings to be compared.
Hence, the total time complexity is O(n*n) = O(n^2).

Space complexity: O(n). extra space for the reverse string rev.

*/



/*

Key Idea for Naive Approach

Start checking the string each time if it is a palindrome and if not, then delete the last character and check again. When the string gets reduced to wither a palindrome or empty then the number of characters deleted from the end till now will be the answer as those characters could have been inserted at the beginning of the original string in the order which will will make the string a palindrome.


*/


class Solution {
public:
    bool palin(string &str) {
        int left = 0;
        int right = str.length() - 1;

        while (left <= right) {
            if (str[left] != str[right]) {
                return false;
            }

            left++;
            right--;
        }
        return true;
    }

    string shortestPalindrome(string s) {
        if (s.length() <= 1) {
            return s;
        }

        int cnt = 0;
        bool flag = false;

        string temp(s);

        while (s.length() > 0) {
            if (palin(temp)) {
                flag = true;
                break;
            }
            else {
                cnt++;
                temp.erase(temp.begin() + temp.length() - 1);
            }
        }

        string toAdd = s.substr(0 + s.length() - cnt, cnt);
        reverse(toAdd.begin(), toAdd.end());

        return (toAdd + s);

    }
};