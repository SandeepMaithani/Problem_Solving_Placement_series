/*

METHOD 1 : Floyd’s Cycle-Finding Algorithm          Verdict : Accepted

Complexity Analysis :

Time Complexity: O(m*log(m)) here m = 2*n and n is total no of intervals.

Space Complexity: O(m). m size vector reqired to store each pair, where m = 2*n.

*/


int minMeetingRooms(vector<Interval> &intervals) {

    vector<pair<int, int>>meeting;

    int count = 0, answer = 0;

    for (int i = 0; i < intervals.size(); i++) {
        meeting.push_back(make_pair(intervals[i].start, 1));
        meeting.push_back(make_pair(intervals[i].end, -1));
    }

    sort(meeting.begin(), meeting.end());

    for (int i = 0; i < meeting.size(); i++) {

        count += meeting[i].second;

        if (count > answer) {
            answer = count;
        }
    }
    return answer;
}