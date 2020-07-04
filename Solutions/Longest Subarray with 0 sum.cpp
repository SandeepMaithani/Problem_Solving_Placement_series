/*

Complexity Analysis:
Time Complexity: O(N), as use of good hashing function will allow insertion and retrieval operations in O(1) time.
Space Complexity: O(N), for the use of extra space to store the prefix array and hashmap.

*/

/*

Key idea is suppose you got sum equal to 5 at any index suppose at 3 not again after adding some element you
again got sum equal to 5 suppose at index 10 then its mean between index 4 to 10 there exist a subarray whose
sum is zero.
And its size will be 10 -3 = 7

*/

int maxLen(int A[], int n)
{
    unordered_map<int, int>hashmap;
    int gmax = INT_MIN;
    int lsum = 0;

    int sum = 0;

    for (int i = 0; i < n; i++) {
        sum += A[i];

        if (sum == 0) {
            lsum = i + 1;
        }
        else if (hashmap.find(sum) != hashmap.end()) {
            lsum = i - hashmap[sum];
        }
        else {
            hashmap[sum] = i;
        }

        if (lsum > gmax) {
            gmax = lsum;
        }
    }

    return gmax;
}