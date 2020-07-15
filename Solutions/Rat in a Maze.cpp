/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(4^(n^2)).
As there are N^2 cells from each cell there are 4 unvisited neighbouring cells. So the time complexity O(4^(N^2).

Space Complexity: O(n^2).
Output matrix is required so an extra space of size n*n is needed.

*/

void storesolution(vector<vector<char>>&solution, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << solution[i][j] << " ";
        }
        cout << endl;
    }
}

void mazekeeper(int m[MAX][MAX], vector<vector<int>>&solution, int n, int row, int col) {

    if (row == n - 1 && col == n - 1 && m[row][col] != 0) {

        solution[row][col] = 1;
        storesolution(solution, n);
        solution[row][col] = 0;

        return;
    }

    if (row < 0 || row >= n || col < 0 || col >= n || m[row][col] == 0 || solution[row][col] == 1) {
        return;
    }

    solution[row][col] = 1;

    mazekeeper(m, solution, n, row + 1, col);
    mazekeeper(m, solution, n, row, col - 1);
    mazekeeper(m, solution, n, row, col + 1);
    mazekeeper(m, solution, n, row - 1, col);

    solution[row][col] = 0;
}

void printPath(int m[MAX][MAX], int n) {

    vector<vector<int>>solution(n, vector<int>(n, 0));

    mazekeeper(m, solution, n, 0, 0);

}



/*

Method : Backtracking              Verdict : Accepted

GFG Solution

*/

void mazekeeper(int m[MAX][MAX], vector<vector<int>>&solution, vector<string>&answer, int n, int row, int col, char dir, string &path) {

    if (row == n - 1 && col == n - 1 && m[row][col] != 0) {

        solution[row][col] = 1;
        path += dir;
        answer.push_back(path);
        solution[row][col] = 0;
        path.pop_back();

        return;
    }

    if (row < 0 || row >= n || col < 0 || col >= n || m[row][col] == 0 || solution[row][col] == 1) {
        return;
    }

    solution[row][col] = 1;

    if (dir != 'S') {
        path += dir;
    }

    mazekeeper(m, solution, answer, n, row + 1, col, 'D', path);
    mazekeeper(m, solution, answer, n, row, col - 1, 'L', path);
    mazekeeper(m, solution, answer, n, row, col + 1, 'R', path);
    mazekeeper(m, solution, answer, n, row - 1, col, 'U', path);

    solution[row][col] = 0;
    path.pop_back();
}

vector<string> printPath(int m[MAX][MAX], int n) {
    vector<string>answer;
    string path = "";
    vector<vector<int>>solution(n, vector<int>(n, 0));

    mazekeeper(m, solution, answer, n, 0, 0, 'S', path);

    return answer;
}