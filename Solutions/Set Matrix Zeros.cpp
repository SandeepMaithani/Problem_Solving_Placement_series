
//Method 1 using extra space
//Time Complexity O(n*m) and Space Complexity O(m*n)

void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int, int>>track;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            if (matrix[i][j] == 0) {
                track.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < track.size(); i++) {

        for (int j = 0; j < matrix[track[i].first].size(); j++) {
            matrix[track[i].first][j] = 0;
        }

        for (int k = 0; k < matrix.size(); k++) {
            matrix[k][track[i].second] = 0;
        }
    }
}

//Method 2 without using extra space
//Time Complexity O(n*m) and Space Complexity O(1)


void setZeroes(vector<vector<int>>& matrix) {

    bool frow = false, fcol = false;

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix[i].size(); j++) {

            if (matrix[i][j] == 0 && i == 0) {
                frow = true;
            }

            if (matrix[i][j] == 0 && j == 0) {
                fcol = true;
            }

            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < matrix.size(); i++) {
        for (int j = 1; j < matrix[i].size(); j++) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    if (frow) {
        for (int j = 0; j < matrix[0].size(); j++) {
            matrix[0][j] = 0;
        }
    }

    if (fcol) {
        for (int i = 0; i < matrix.size(); i++) {
            matrix[i][0] = 0;
        }
    }
}