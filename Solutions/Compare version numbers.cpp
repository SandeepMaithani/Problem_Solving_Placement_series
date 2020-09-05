/*

Complexity Analysis:-                                Verdict : Accepted

Time Complexity : O(Max(M,N)). Where M and N are the length of first and second string.

Expected Auxilliary Space : O(1).

*/



/*

Key idea is for both the version we will extract the number before each '.' and compare them to check in which
which version is greater/smaller.

eg : 2.05.43    and   2.05.42

so : first we compare "2" then  "05" then "43" and so on.

*/

class Solution {
public:
    int compareVersion(string version1, string version2) {

        int num1, num2;
        int i = 0, j = 0;

        while (i < version1.length() || j < version2.length()) {
            num1 = num2 = 0;

            while (i < version1.length() && version1[i] != '.') {
                num1 = num1 * 10 + (version1[i] - '0');
                i++;
            }
            while (j < version2.length() && version2[j] != '.') {
                num2 = num2 * 10 + (version2[j] - '0');
                j++;
            }

            if (num1 > num2) {
                return 1;
            }
            else if (num2 > num1) {
                return -1;
            }

            i++;
            j++;
        }

        return 0;
    }
};