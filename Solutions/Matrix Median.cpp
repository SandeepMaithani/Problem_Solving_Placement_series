/*

Method 1 : Binary Search               Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N*log(M)).

Time taken by upper_bound function is log(M) for a array of size M and we are finding upper_bound for N rows so O(N*Log(M))

Space Complexity: O(1).

*/

/*

Solution idea

Let us see a step-by-step approach to this solution:

 1. First, we need to find the minimum and maximum elements from the matrix. The minimum and maximum can be easily found since the rows are sorted so we need to comapare with the first element of each row for minimum and last element of each row for maximum.

 2. After finding our min and max, we can apply binary search on this range. The mid element can be calculated and number of elements smaller or equal to mid can be calculated, we have used upper_bound() function for this.

 3. Based on the value of our counter, the min and max can be adjusted accordingly based on what we do for binary search.


*/


#include<bits/stdc++.h>
using namespace std;

int matmedian(vector<vector<int>>&matrix, int n, int m) {
    int min = INT_MAX;
    int max = INT_MIN;

    int count_needed = (1 + (n * m)) / 2;

    for (int i = 0; i < n; i++) {
        if (min > matrix[i][0]) {
            min = matrix[i][0];
        }
        if (max < matrix[i][m - 1]) {
            max = matrix[i][m - 1];
        }
    }

    while (min < max) {
        int counter = 0;

        int mid = min + (max - min) / 2;

        for (int i = 0; i < n; i++) {
            counter += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
        }

        if (counter < count_needed) {
            min = mid + 1;
        }
        else {
            max = mid;
        }
    }
    return min;
}

int main() {

    int n, m;
    cin >> n >> m;

    vector<vector<int>>matrix(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> matrix[i][j];
        }
    }

    int answer = matmedian(matrix, n, m);

    cout << answer << endl;

}




/*

Method 1 : Brute Force              Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N*M*(log(N*M))).

Time taker by sort function to sort a vector of N*M element

Space Complexity: O(N*M).

Space required to store all the element of matrix in a vector.

*/

/*

Solution idea :-

1. First, create an array of size N*M and copy all the elements of the matrix in that array. You can copy either row-wise or column-wise.

2. After copying simply sort the entire array.

3. Output the element at the [(1+N*M)/2–1]th index as this will be the middle element partitioning the array in lower and upper halves.


*/