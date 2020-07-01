
//Method 1
// Time Complexity O(nlog(n))
//Space Complexity O(1)

int findDuplicate(vector<int>& nums) {
	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] == nums[i + 1]) {
			return nums[i];
		}
	}
	return -1;
}

//Method 2 when we have a read only array
//Floyd's Tortoise and Hare (Cycle Detection) in simple words 2 pointer (fast and slow)
//Time Complexity O(N) & Space Complexity O(1)

int findDuplicate(vector<int>& nums) {
	int slow = nums[0];
	int fast = nums[nums[0]];

	while (fast != slow) {
		slow = nums[slow];
		fast = nums[nums[fast]];
	}

	fast = 0;

	while (fast != slow) {
		slow = nums[slow];
		fast = nums[fast];
	}
	return slow;
}