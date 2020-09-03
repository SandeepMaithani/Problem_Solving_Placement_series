/*

Method 1 : KMP Algorithm                  Verdict : Accepted

Complexity Analysis: O(|Text|).

We will look weather pattern is a substring of Text or not using KMP pattern matching Algorithm.

Time Complexity: O(|Pattern|).

KMP Algo require a extra array to keep a track of substring which are also a prefix.

*/

class Solution {
public:
    void prefixSub(string &pattern, vector<int>&lenKeeper) {
        int len = 0;
        int i = 1;

        lenKeeper[0] = 0;

        while (i < pattern.length()) {
            if (pattern[len] == pattern[i]) {
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
    }

    int KMPSearch(string &text, string &pattern) {
        vector<int>lenKeeper(pattern.length());
        prefixSub(pattern, lenKeeper);

        int i = 0, j = 0;

        while (i < text.length() && j < pattern.length()) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }
            else {
                if (j == 0) {
                    i++;
                }
                else {
                    j = lenKeeper[j - 1];
                }
            }
        }

        if (j == pattern.length()) {
            return i - j;
        }

        return -1;
    }

    int strStr(string haystack, string needle) {
        int ptlen = needle.length();
        int stlen = haystack.length();

        if (ptlen == 0 || (ptlen == 0 && stlen == 0)) {
            return 0;
        }
        else if (ptlen <= stlen) {
            return KMPSearch(haystack, needle);
        }

        return -1;
    }
};


/*

Method 2 : Two Pointers                       Verdict : Accepted

Complexity Analysis: O(|Text|*|Pattern|).

We are checking at each position of text weather Pattern exist or not.

Time Complexity: O(1). No extra space required.

*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int ptlen = needle.length();
        int stlen = haystack.length();

        if (ptlen == 0 || (ptlen == 0 && stlen == 0) || ptlen > stlen) {
            return 0;
        }
        else {

            for (int i = 0; i <= (stlen - ptlen); i++) {
                int ptr1 = i;
                int ptr2 = 0;

                while (ptr2 < ptlen) {
                    if (haystack[ptr1] == needle[ptr2]) {
                        ptr1++;
                        ptr2++;
                    }
                    else {
                        break;
                    }
                }

                if (ptr2 == ptlen) {
                    return i;
                }
            }
        }
        return -1;

    }
};

