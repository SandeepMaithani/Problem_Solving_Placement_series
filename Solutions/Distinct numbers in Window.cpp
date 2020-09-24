/*

Method 1 : Sliding  window                                Verdict : Accepted

Complexity Analysis:

Time complexity O(N).  As single traversal of the array is required and N is the size of the array.

Space Compelxity O(N). Since, we use a hashmap and hashmap requires linear space.

*/

vector <int> countDistinct (int A[], int n, int k)
{
    unordered_map<int, int>hashmap;
    vector<int>answer;
    int uniqueNum = 0;

    for (int i = 0; i < k; i++) {

        if (hashmap[A[i]] == 0) {
            uniqueNum++;
        }

        hashmap[A[i]]++;
    }

    answer.push_back(uniqueNum);

    for (int i = 1; i <= n - k; i++) {
        if (hashmap[A[i - 1]] == 1) {
            uniqueNum--;
        }

        hashmap[A[i - 1]]--;

        if (hashmap[A[i + k - 1]] == 0) {
            uniqueNum++;
        }

        hashmap[A[i + k - 1]]++;

        answer.push_back(uniqueNum);
    }

    return answer;
}



/*

Method 2 : Brute Froce                                Verdict : TLE

Complexity Analysis:

Time complexity: O(N*(k^2)).

The time complexity can be improved to O(n*k*log k) by modifying countWindowDistinct() by the use of sorting. The function can further be optimized to use hashing to find distinct elements in a window. With hashing the time complexity becomes O(n*k).

Space Complexity: O(1) we no any extra space is needed.

*/


/*

idea here is we will generate all the substring and then will find distinct character in each substring.


*/