
// Method 1 by keeping count of 0s,1s and 2s
//Time Complexity O(N) space complexity O(1)

void sortColors(vector<int>& nums) {

    vector<int>count(3, 0);

    for (auto i : nums) {
        count[i]++;
    }

    int tre = 0;

    for (int j = 0; j < nums.size();) {

        while (count[tre] != 0) {

            nums[j] = tre;
            j++;
            count[tre]--;
        }

        tre++;
    }
}

// Method 2 shifting 0s to left and 2s to right and automatically 1s will come in middle
//Time Complexity O(N) space complexity O(1) in single pass

void sortColors(vector<int>& nums) {

    int start = 0;
    int mid = 0;
    int end = nums.size() - 1;

    while (mid <= end && start <= mid) {

        if (nums[mid] == 0) {

            nums[mid] = nums[start];
            nums[start] = 0;
            start++;
            mid++;
        }
        else if (nums[mid] == 2) {

            nums[mid] = nums[end];
            nums[end] = 2;
            end--;
        }
        else {
            mid++;
        }
    }
}