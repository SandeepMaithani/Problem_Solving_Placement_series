
//Time Complexity O(N*N) and Space Complexity O(N*N)

vector<vector<int>> generate(int numRows) {

    vector<vector<int>>answer;

    if (numRows == 0) {
        return answer;
    }

    vector<int>temp1;
    temp1.push_back(1);
    answer.push_back(temp1);

    if (numRows == 1) {
        return answer;
    }

    temp1.push_back(1);
    answer.push_back(temp1);

    if (numRows == 2) {
        return answer;
    }

    for (int i = 2; i < numRows; i++) {
        vector<int>temp;
        temp.push_back(1);

        for (int j = 1; j < i; j++) {
            int x = answer[i - 1][j - 1] + answer[i - 1][j];
            temp.push_back(x);
        }
        temp.push_back(1);
        answer.push_back(temp);
    }

    return answer;
}