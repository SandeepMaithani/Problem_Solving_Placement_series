/*

Method 1 : Hashing and using equation                                    Verdict : Accepted

Complexity Analysis:

Time Complexity: O(N), as use of good hashing function will allow insertion and retrieval operations in O(1) time.

Space Complexity: O(N), for the use of extra space to store the prefix array and hashmap.

*/


/*

Intution : - Here we will use a equal (Y = X ^ K).

https://www.youtube.com/watch?v=lO9R5CaGRPY&t=1s


*/


int subarrayCounter(vector<int> &nums, int k) {
	unordered_map<int, int>hashMap;
	int count = 0, prefiXor = 0;

	for (int i = 0; i < nums.size(); i++) {
		prefiXor = prefiXor ^ nums[i];

		if (prefiXor == k) {
			count++;
		}

		if (hashMap.find(prefiXor ^ k) != hashMap.end()) {
			count = count + hashMap[prefiXor ^ k];
		}

		hashMap[prefiXor]++;
	}

	return count;
}





/*

Method 2 : Brute Force                                    Verdict : TLE

Complexity Analysis:

Time Complexity: O(N*N), We will find the xor of all the subarray and count all subarray with xor equal to k.

Space Complexity: O(1), No extra space required.

*/



/*

Intution : We will find xor of all the subarray one by one and  count the no of subarray having xor equal to given number K.


*/