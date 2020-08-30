/*

Method 1                             Verdict: Accepted

Complexity Analysis:

Time complexity: O(N). where n is the length of input string.

Space complexity: O(1).No extra space is needed.

*/


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>hashmap {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int number = 0;

        if (s.length() == 0) {
            return number;
        }

        for (int i = 0; i < s.length() - 1; i++) {
            if (hashmap[s[i]] < hashmap[s[i + 1]]) {
                number -= hashmap[s[i]];
            }
            else {
                number += hashmap[s[i]];
            }
        }

        return number + hashmap[s[s.length() - 1]];
    }
};



/*

Method 2                             Verdict: Accepted

Complexity Analysis:

Time complexity: O(N). where n is the length of input string.

Space complexity: O(1).No extra space is needed.

*/


class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>hashmap {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int number = 0;

        if (s.length() == 0) {
            return number;
        }

        number += hashmap[s[0]];

        for (int i = 1; i < s.length(); i++) {
            if (hashmap[s[i]] <= hashmap[s[i - 1]]) {
                number += hashmap[s[i]];
            }
            else {
                number += hashmap[s[i]] - 2 * (hashmap[s[i - 1]]);
            }
        }

        return number;
    }
};