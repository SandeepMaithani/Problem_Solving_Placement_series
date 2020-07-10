/*

Method 1 :- Sliding Window(Two Pointers Variation)          Verdict : Accepted

Complexity Analysis :

Time complexity: O(n) Single iteration on n element array.

Space complexity: O(1) extra space.

*/

int longestOnes(vector<int>& A, int k) {

    int start = 0;
    int end = 0;

    while (end < A.size()) {

        if (A[end] == 0) {
            k--;
        }

        if (k < 0) {

            if (A[start] == 0) {
                k++;
            }

            start++;
        }

        end++;
    }

    return end - start;
}