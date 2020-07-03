
//Method 1 DP on grid
//Time Complexity O(M*N) and Space Complexity O(M*N)

int uniquePaths(int m, int n) {
    int dp[m][n];

    for (int i = 0; i < m; i++) {
        dp[i][0] = 1;
    }

    for (int j = 0; j < n; j++) {
        dp[0][j] = 1;
    }

    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    return dp[m - 1][n - 1];
}


//Method 2

//Combinatorics solution complexity O(max(A,B))

/*
Explaination
for 3*3 we will have something like "RRDD" we can see no 'R' and 'D' of
will always be fixed which can be arranged in as
[4!/(2!*2!)] ways where 'R' and 'D' are repeated twice
or
{[((A-1)+(B-1))!]/[(A-1)! * (B-1)!]} == (A+B-2)C(A-1)

*/

//This function is time and space efficient nCr function

int comb(int n, int k) {
    long long res = 1;

    if (k > n - k) {
        k = n - k;
    }

    for (int i = 0; i < k; i++) {
        res *= n - i;
        res /= i + 1;
    }

    return (int)res;
}

int uniquePaths(int m, int n) {

    int answer = 1;

    if (m == 1 || n == 1) {
        return answer;
    }
    else {
        answer = comb(m + n - 2, m - 1);
    }

    return answer;
}