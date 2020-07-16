//Case II :- When there are duplicate elements in the array

/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(n*n!).

Note that there are n! permutations and it require O(n) to look for duplicate so O(n*n!).

Space Complexity: O(1).

*/

class Solution {
public:
    void swap(vector<int>&nums, int first, int second) {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

    bool isvalid(vector<int>& nums, int start, int curr) {
        for (int i = start; i < curr; i++) {
            if (nums[i] == nums[curr]) return false;
        }
        return true;
    }

    void storepermute(vector<int>& nums, vector<vector<int>>&ans, int left, int right) {
        if (left == right) {
            ans.push_back(nums);
        }
        for (int mover = left; mover <= right; mover++) {
            bool check = isvalid(nums, left, mover);

            if (check) {
                swap(nums, mover, left);
                storepermute(nums, ans, left + 1, right);
                swap(nums, mover, left);
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        if (n == 0) {
            return ans;
        }
        if (n == 1) {
            ans.push_back(nums);
            return ans;
        }

        sort(nums.begin(), nums.end());

        storepermute(nums, ans, 0, n - 1);

        return ans;
    }
};


//Little bit tricky instead of swapping it back we use call by value and avoid swapping back to maintain sorted order and to avoid getting duplicate permutations.

/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(n!).

Note that there are n! permutations so O(n!). And it requires O(n) time to print a permutation so if we print the permutation then it will become O(n*n!).

Space Complexity: O(n!).

*/

class Solution {
public:
    void swap(vector<int>&nums, int first, int second) {
        int temp = nums[first];
        nums[first] = nums[second];
        nums[second] = temp;
    }

    void storepermute(vector<int> nums, vector<vector<int>>&ans, int left, int right) {
        if (left == right) {
            ans.push_back(nums);
            return;
        }

        for (int mover = left; mover <= right; mover++) {
            if (mover != left && nums[mover] == nums[left]) {
                continue;
            }
            swap(nums, mover, left);
            storepermute(nums, ans, left + 1, right);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        int n = nums.size();

        if (n == 0) {
            return ans;
        }
        if (n == 1) {
            ans.push_back(nums);
            return ans;
        }

        sort(nums.begin(), nums.end());

        storepermute(nums, ans, 0, n - 1);

        return ans;
    }
};