/*

Using Backtracking        Verdict : Accepted

Complexity Analysis:

Time complexity: O(9^(n*n)).

For every unassigned index there are 9 possible options so the time complexity is O(9^(n*n)).

Space Complexity: O(1) or O(n*n).

If grid is not given then to store output matrix is needed.

*/

class Solution {
public:
    bool isvalid(vector<vector<char>>& board, char ch, int i, int j) {

        for (int check = 0; check < 9; check++) {
            if (board[check][j] == ch || board[i][check] == ch) {
                return false;
            }
        }
        int rowAdjust = i - i % 3;
        int colAdjust = j - j % 3;

        for (int row = 0; row < 3; row++) {
            for (int col = 0; col < 3; col++) {
                if (board[row + rowAdjust][col + colAdjust] == ch) {
                    return false;
                }
            }
        }
        return true;
    }

    bool solveSudoku(vector<vector<char>>& board) {

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {

                    for (char ch = '1'; ch <= '9'; ch++) {
                        if (isvalid(board, ch, i, j)) {
                            board[i][j] = ch;
                            if (solveSudoku(board)) {
                                return true;
                            }
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
};