/*

Complexity Analysis

Time Complexity: O(N). Here, N is the length of string str. We perform only one iteration over string str.
Space Complexity: O(1). We use constant extra space for storing sign of the result.

*/


class Solution {
public:
    int myAtoi(string str) {
        if (str.length() == 0) {
            return 0;
        }

        int signcnt = 0;
        int negFlag = false;
        int i = 0;

        long result = 0;

        while (i < str.length() && str[i] == ' ') {
            i++;
        }

        while (i < str.length() && (str[i] == '+' || str[i] == '-')) {
            signcnt++;

            if (signcnt > 1) {
                return 0;
            }
            if (str[i] == '-') {
                negFlag = true;
            }

            i++;
        }

        while (i < str.length() && str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');

            if (negFlag && result > INT_MAX) {
                return INT_MIN;
            }
            else if (result > INT_MAX) {
                return INT_MAX;
            }

            i++;
        }

        if (negFlag) {
            result = -result;
        }

        return (int)result;
    }
};