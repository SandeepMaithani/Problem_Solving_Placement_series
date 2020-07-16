
//Case I :- When there are distinct element in the array

/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(n!).

Note that there are n! permutations so O(n!). And it requires O(n) time to print a permutation so if we print the permutation then it will become O(n*n!).

Space Complexity: O(1).

*/

class Solution {
public:

    void swap(vector<int>&nums, int first, int second) {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

    void storepermute(vector<int>& nums, vector<vector<int>>&ans, int left, int right) {
        if (left == right) {
            ans.push_back(nums);
        }
        for (int mover = left; mover <= right; mover++) {
            swap(nums, mover, left);
            storepermute(nums, ans, left + 1, right);
            swap(nums, mover, left);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        if (n == 0) {
            return ans;
        }
        if (n == 1) {
            ans.push_back(nums);
            return ans;
        }

        storepermute(nums, ans, 0, n - 1);

        return ans;
    }
};

