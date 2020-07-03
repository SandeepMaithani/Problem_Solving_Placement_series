
// Time Complexity O(N) and Space Complexity O(1)

void swap(vector<int>& nums, int i, int j) {
    int temp = nums[i];
    nums[i] = nums[j];
    nums[j] = temp;
}

void reverse(vector<int>& nums, int i, int j) {
    while (i < j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(vector<int>& nums) {

    int n = nums.size();

    if ( n == 1) {
        return;
    }
    else if ( n == 2) {
        swap(nums, 0, 1);
    }
    else {
        int i = n - 2;

        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            int j = n - 1;

            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }

            swap(nums, i, j);
            reverse(nums, i + 1, n - 1);

        }
        else {
            reverse(nums, 0, n - 1);
        }
    }
}