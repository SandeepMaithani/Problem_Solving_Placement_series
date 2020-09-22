/*

Method 1 : Using Min Heap                                   Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N*log(K)). We are processing every element once heap take log(K) time to push to O(N*log(K)).

Space Complexity: O(K). K size heap used.

*/

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        priority_queue<int, vector<int>, greater<int>> min_heap;

        for (int i = 0; i < nums.size(); i++) {
            min_heap.push(nums[i]);

            if (min_heap.size() > k) {
                min_heap.pop();
            }
        }

        return min_heap.top();
    }
};

/*

Method 2 : Using Sort function                                   Verdict : Accepted

Complexity Analysis :

Time Complexity: O(N*log(N)). Time complexity of sort function.

Space Complexity: O(1).

*/

int findKthLargest(vector<int>& nums, int k) {

    sort(nums.begin(), nums.end());

    return nums[nums.size() - k + 1];
}
