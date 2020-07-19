/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(N * 2^N).

Total O(2^N) recursive calls.For every call we do:

1) check ifPalindrome O(N)
2) create substring O(N)

therefore total time complexity will be O(n * 2^n).

Space Complexity: O(N).

Memory would be O(N). Due to recursion tree (which depth is at most n).

*/


bool ispalin(string s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void helper(vector<vector<string>>&solution, vector<string>&answer, string s, int start)
{
    if (start >= s.length()) {
        solution.push_back(answer);
        return;
    }

    for (int pos = start; pos < s.length(); pos++) {

        if (ispalin(s, start, pos)) {

            answer.push_back(s.substr(start, pos - start + 1));
            helper(solution, answer, s, pos + 1);
            answer.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>>solution;
    vector<string>answer;

    helper(solution, answer, s, 0);

    return solution;

}