/*

Method 1 : Binary Search + pairwise index property              Verdict : Accepted

Complexity Analysis :

Time Complexity: O(log(N)).

Time taken by Binary search approach

Space Complexity: O(1).

*/

/*

Key Idea :-

All elements before the required have the first occurrence at even index (0, 2, ..) and next occurrence at odd index (1, 3, …).
And all elements after the required elements have the first occurrence at odd index and next occurrence at even index.

based on this property we will move left or right i.e :- if mid is even then our answer will be in right part or else in left part


*/

int singleNonDuplicate(vector<int>& nums) {

	int left = 0;
	int right = nums.size() - 1;

	if (right == 0 || nums[0] != nums[1]) {
		return nums[0];
	}
	else if (nums[right] != nums[right - 1]) {
		return nums[right];
	}

	while (left <= right) {
		int mid = left + (right - left) / 2;

		if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1]) {
			return nums[mid];
		}

		if ((mid % 2 == 0 && nums[mid] == nums[mid + 1]) || (mid % 2 == 1 && nums[mid] == nums[mid - 1])) {
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	return -1;
}