/*

METHOD 1 : 2 pointer and skipping duplicate         Verdict : Accepted

Complexity Analysis

Time Complexity: O(n*n) Only one traversal of the loop and one traversal to find 2SUM is needed.

Space Complexity: O(1).

*/


vector<vector<int>> threeSum(vector<int>& nums) {

    int n = nums.size();

    vector<vector<int>>solution;

    if (n < 3 ) {
        return solution;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 2; i++) {

        if (i == 0 || nums[i] != nums[i - 1]) {

            int left = i + 1;
            int right = n - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];

                if (sum == 0) {
                    solution.push_back({nums[i], nums[left], nums[right]});

                    while (left < right && nums[left] == nums[left + 1]) {
                        left++;
                    }
                    while (left < right && nums[right] == nums[right - 1]) {
                        right--;
                    }

                    left++;
                    right--;
                }
                else if (sum > 0) {
                    right--;
                }
                else {
                    left++;
                }
            }
        }
    }

    return solution;
}



/*

METHOD 2 : 2 pointer and SET        Verdict : Accepted

Complexity Analysis

Time Complexity: O(N*N*(M*log(M))) where M is no of triplet which take M*log(M) time to insert M triplet in Set as unordered_set is not working here.

Space Complexity: O(M).

*/

vector<vector<int>> threeSum(vector<int>& nums) {

    vector<vector<int>>solution;
    set<vector<int>>hashset;

    if (nums.size() <= 1 ) {
        return solution;
    }

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size() - 2; i++) {

        int sum = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right) {
            if ((nums[left] + nums[right]) > sum) {
                right--;
            }
            else if ((nums[left] + nums[right]) < sum) {
                left++;
            }
            else {
                hashset.insert({nums[i], nums[left++], nums[right--]});
            }
        }
    }

    for (auto li : hashset) {
        solution.push_back(li);
    }
    return solution;
}