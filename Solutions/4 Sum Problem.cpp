/*

Method 1 : Using Two Pointer and sort                            verdict : Accepted

Complexity Analysis:

Time Complexity: O(N^3), Where N is the size of the array we are using two nested loops to find initial 2 numbers and thereafter using two sum technique to find next two number which require O(N) time so overall it is O(n^3).

Space Compelxity: O(1), No extra space require.

*/

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>>solution;
		int size = nums.size();

		if (size <= 3) {
			return solution;
		}

		sort(nums.begin(), nums.end());

		for (int i = 0; i < size; i++) {
			for (int j = i + 1; j < size; j++) {
				int smallTarget = target - nums[i] - nums[j];
				int left = j + 1;
				int right = size - 1;

				while (left < right) {
					int sum = nums[left] + nums[right];

					if (sum < smallTarget) {
						left++;
					}
					else if (sum > smallTarget) {
						right--;
					}
					else {
						vector<int>quadruplets(4);
						quadruplets[0] = nums[i];
						quadruplets[1] = nums[j];
						quadruplets[2] = nums[left];
						quadruplets[3] = nums[right];

						solution.push_back(quadruplets);

						while (left < right && nums[left] == quadruplets[2]) {
							left++;
						}

						while (left < right && nums[right] == quadruplets[3]) {
							right--;
						}
					}
				}

				while (j + 1 < size && nums[j] == nums[j + 1]) {
					j++;
				}
			}

			while (i + 1 < size && nums[i] == nums[i + 1]) {
				i++;
			}
		}

		return solution;
	}
};


/*

Method 2 : using sorting,Binary search and hashset                        verdict : Accepted

Complexity Analysis:

Time Complexity: O(N^3 * Log(N)), Where N is the size of the array we are using three nested loops to find last number using binary search which take log(N) time so overall it is O(N^3 * log(N)).

Space Compelxity: O(N), we are using hashTable to avoid duplicates.

*/


/*

Intution :- First we will remove all the dupliates from the nums to do so we will use set this will remove all the duplicates quadruples possiblities and then we will use three loops to get three number and now to get last number we will use binary search to find the last number exist or not such that it form require sum with all three number.

*/



/*

Method 3 : Complete Brute force                         verdict : TLE

Complexity Analysis:

Time Complexity: O(N^4). We will use for nested loops to get the four numbers.

Space Compelxity: O(1).

*/