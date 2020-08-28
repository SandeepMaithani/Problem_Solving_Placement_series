/*

Method 1 : Using Deque               Verdict : Accepted

Compelxity Analysis:

Time Complexity: O(n).

It seems more than O(n) at first look. It can be observed that every element of array is added and removed at most once. So there are total 2n operations.

Space Complexity: O(k).

Elements stored in the dequeue take O(k) space.

*/

/*

Approach:

Create a Deque of capacity k, that stores only useful elements of current window of k elements. An element is useful if it is in current window and is greater than all other elements on left side of it in current window. Process all array elements one by one and maintain Deque to contain useful elements of current window and these useful elements are maintained in sorted order. The element at front of the Deque is the largest and element at rear of Deque is the smallest of current window.

*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int>answer;
        deque<int>helper;

        for (int i = 0; i < k; i++) {

            while (!helper.empty() && nums[i] >= nums[helper.back()]) {
                helper.pop_back();
            }

            helper.push_back(i);
        }

        answer.push_back(nums[helper.front()]);

        for (int i = k; i < n; i++) {

            if (!helper.empty() && i - k >= helper.front()) {
                helper.pop_front();
            }

            while (!helper.empty() && nums[i] >= nums[helper.back()]) {
                helper.pop_back();
            }

            helper.push_back(i);
            answer.push_back(nums[helper.front()]);
        }

        return answer;
    }
};



/*

Method 2 : Using Stack               Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N)

Only two traversal of the array is needed. So Time Complexity is O(n).

Space Complexity: O(N)

Two extra space of size n is required.

*/



/*

Key idea here is we will find the next greater element for each element and now we will find maximum greater element within the window by checking the next greater element of current greater element within our window.

*/



class Solution {
public:
    void nextGreaterElement(vector<int>& nums, vector<int>& nextElement) {
        stack<int>st;

        for (int i = nums.size() - 1; i >= 0; i--) {
            if (st.empty()) {
                nextElement.push_back(nums.size());
            }
            else if (nums[st.top()] > nums[i]) {
                nextElement.push_back(st.top());
            }
            else {
                while (!st.empty() && nums[st.top()] <= nums[i]) {
                    st.pop();
                }
                if (st.empty()) nextElement.push_back(nums.size());
                else {
                    nextElement.push_back(st.top());
                }
            }
            st.push(i);
        }
        reverse(nextElement.begin(), nextElement.end());
    }

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>answer;
        vector<int>nextElement;

        int n = nums.size();

        nextGreaterElement(nums, nextElement);

        int maxptr = 0;

        for (int i = 0; i <= n - k; i++) {

            if (maxptr < i) {
                maxptr = i;
            }

            while (nextElement[maxptr] < i + k) {
                maxptr = nextElement[maxptr];
            }
            answer.push_back(nums[maxptr]);
        }
        return answer;
    }
};
