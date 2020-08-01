/*

Complexity Analysis :                         Verdict : Accepted

Time Complexity: O(N). Since every bar is pushed and popped only once, the time complexity of this method is O(n).

Space Complexity: O(N). N size stack used.

*/


class Solution {
public:

    void filleft(vector<int>&heights, vector<int>&left) {
        stack<int>st;
        int corner = -1;

        for (int i = 0; i < heights.size(); i++) {
            if (st.empty()) {
                left.push_back(corner);
            }
            else if (heights[st.top()] < heights[i]) {
                left.push_back(st.top());
            }
            else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    left.push_back(corner);
                }
                else {
                    left.push_back(st.top());
                }
            }
            st.push(i);
        }
    }

    void fillright(vector<int>&heights, vector<int>&right) {
        stack<int>st;
        int corner = heights.size();

        for (int i = corner - 1; i >= 0; i--) {
            if (st.empty()) {
                right.push_back(corner);
            }
            else if (heights[st.top()] < heights[i]) {
                right.push_back(st.top());
            }
            else {
                while (!st.empty() && heights[st.top()] >= heights[i]) {
                    st.pop();
                }
                if (st.empty()) {
                    right.push_back(corner);
                }
                else {
                    right.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(right.begin(), right.end());
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();

        if (n == 0) return 0;

        if (n == 1) return heights[0];

        vector<int>left, right, area;

        filleft(heights, left);
        fillright(heights, right);

        for (int i = 0; i < n; i++) {
            int width = right[i] - left[i] - 1;
            int answer = width * heights[i];
            area.push_back(answer);
        }

        return *max_element(area.begin(), area.end());
    }
};