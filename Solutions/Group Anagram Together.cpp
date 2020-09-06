/*

Method 1:- Using count sort to sort the array                   Verdict : Accepted

Complexity Analysis :-

Time Complexity: O(N*K).

where N is the length of array of strings, and K is the maximum length of a string in that array. Counting each string is linear in the size of the string, and we count every string.

Space Complexity: O(N*K). The total information content stored in Map to group similar anagram.

*/


class Solution {
public:
    string countSort(string &str) {
        string sorted = "";
        vector<int>hash(26, 0);

        for (int i = 0; str[i]; i++) {
            hash[str[i] - 'a']++;
        }

        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < hash[i]; j++) {
                sorted += (char)('a' + i);
            }
        }
        return sorted;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>solution;

        if (strs.size() == 0) {
            return solution;
        }

        unordered_map<string, vector<string>>hashmap;

        for (string word : strs) {
            string key = countSort(word);
            hashmap[key].push_back(word);
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
            solution.push_back(it->second);
        }
        return solution;
    }
};



/*

Method 2:- Using built in function to sort the array                   Verdict : Accepted

Complexity Analysis :-

Time Complexity: O(N*(K*log(K))).

where N is the length of array of strings, and K is the maximum length of a string in that array. The outer loop has complexity O(N) as we iterate through each string. Then, we sort each string in O(K*log(K)) time.

Space Complexity: O(N*K). The total information content stored in Map to group similar anagram.

*/


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>solution;

        if (strs.size() == 0) {
            return solution;
        }

        unordered_map<string, vector<string>>hashmap;

        for (string word : strs) {

            string key = word;
            sort(key.begin(), key.end());

            hashmap[key].push_back(word);
        }

        for (auto it = hashmap.begin(); it != hashmap.end(); it++) {
            solution.push_back(it->second);
        }
        return solution;
    }
};