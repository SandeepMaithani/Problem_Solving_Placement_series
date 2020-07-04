// Method 1  Verdict : Accepted

/*

Complexity Analysis

Time complexity : O(N).

Although the time complexity appears to be quadratic due to the while loop nested within the for loop,
closer inspection reveals it to be linear. Because the while loop is reached only when 'num' marks the
beginning of a sequence (i.e. 'num'-1 is not present in nums), the while loop can only run for N iterations
throughout the entire runtime of the algorithm. This means that despite looking like O(N*N) complexity, the
nested loops actually run in O(N + N) = O(N) time. All other computations occur in constant time, so the overall
runtime is linear.

Space complexity : O(N).

In order to set up O(1) containment lookups, we allocate linear space for a hash table to store the O(N) numbers
in nums. Other than that, the space complexity is identical to that of the brute force solution.

*/


int longestConsecutive(vector<int>& nums) {

	if (nums.size() == 0) {
		return 0;
	}
	if (nums.size() == 1) {
		return 1;
	}

	unordered_set<int>hashset(nums.begin(), nums.end());

	int max = 0;

	for (auto num : hashset) {

		if (hashset.find(num - 1) == hashset.end()) {

			int check = num;
			int lmax = 1;

			while (hashset.find(check + 1) != hashset.end()) {

				check += 1;
				lmax += 1;

			}

			if (lmax > max) {
				max = lmax;
			}
		}
	}

	return max;

}

// Method 2   Verdict : Accepted

/*

Complexity Analysis

Time complexity : O(N*Log(N)).

The main for loop does constant work N times, so the algorithm's time complexity is dominated by the invocation
of sort, which will run in  O(N*Log(N)) time for any sensible implementation.

Space complexity : O(1) or O(N).

For the implementations provided here, the space complexity is constant because we sort the input array in place. If we are not allowed to modify the input array, we must spend linear space to store a sorted copy.

*/

int longestConsecutive(vector<int>& nums) {

	int max = 0, lmax = 1;

	if (nums.size() == 0) {
		return max;
	}

	if (nums.size() == 1) {
		return lmax;
	}

	sort(nums.begin(), nums.end());

	for (int i = 0; i < nums.size() - 1; i++) {
		if (nums[i] + 1 == nums[i + 1]) {
			lmax++;
		}
		if (nums[i] + 1 < nums[i + 1]) {
			lmax = 1;
		}
		if (lmax > max) {
			max = lmax;
		}
	}

	return max;
}


// Method 3  verdict : TLE

/*

Complexity Analysis

Time complexity : O(N^3)

The outer loop runs exactly nn times, and because currentNum increments by 1 during each iteration of the while
loop, it runs in O(N) time. Then, on each iteration of the while loop, an O(N) lookup in the array is performed. Therefore, this brute force algorithm is really three nested O(N) loops, which compound multiplicatively to a cubic runtime.

Space complexity : O(1).

The brute force algorithm only allocates a handful of integers, so it uses constant additional space.

*/



bool present(vector<int> &nums, int target) {
	for (int i = 0; i < nums.size(); i++) {
		if (nums[i] == target) {
			return true;
		}
	}
	return false;
}

int longestConsecutive(vector<int>& nums) {
	int max = 0, lmax = 1;

	if (nums.size() == 0) {
		return max;
	}

	if (nums.size() == 1) {
		return lmax;
	}

	for (int num : nums) {
		int check = num;
		lmax = 1;

		while (present(nums, check + 1)) {
			check += 1;
			lmax++;
		}

		if (max < lmax) {
			max = lmax;
		}
	}
	return max;
}