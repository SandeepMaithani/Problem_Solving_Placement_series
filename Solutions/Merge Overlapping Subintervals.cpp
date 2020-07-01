
//Time Complexity O(N*log(N))
//Space Complexity O(N)

vector<vector<int>> merge(vector<vector<int>>& intervals) {

    if (intervals.size() == 0) {
        return intervals;
    }

    sort(intervals.begin(), intervals.end());

    vector<vector<int>> answer;

    answer.push_back(intervals[0]);

    for (int i = 1; i < intervals.size(); i++) {

        if (answer[answer.size() - 1][1] >= intervals[i][0]) {

            answer[answer.size() - 1][1] = max(answer[answer.size() - 1][1], intervals[i][1]);
        }
        else {
            answer.push_back(intervals[i]);
        }
    }

    return answer;

}