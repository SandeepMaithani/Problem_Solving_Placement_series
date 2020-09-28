/*

Method 1 : Using Enhance Merge Sort                            verdict : Accepted

Complexity Analysis:

Time Complexity: O(N*log(N)), The algorithm used is divide and conquer, So in each level one full array traversal is needed and there are log(N) levels so the time complexity is O(N*log(N)).

Space Compelxity: O(n), space require to store the Temporary array.

*/



long merge(vector<int> &arr, vector<int> &temp, int left, int mid, int right) {
	int first, second, third;
	long invCount = 0;

	first = left;
	second = mid;
	third = left;

	while ((first <= mid - 1) && (second <= right)) {
		if (arr[first] <= arr[second]) {
			temp[third] = arr[first];
			third++;
			first++;
		}
		else {
			temp[third] = arr[second];
			third++;
			second++;
			invCount += (mid - first);
		}
	}

	while (first <= mid - 1) {
		temp[third] = arr[first];
		third++;
		first++;
	}

	while (second <= right) {
		temp[third] = arr[second];
		third++;
		second++;
	}

	for (int i = left; i <= right; i++) {
		arr[i] = temp[i];
	}

	return invCount;

}

long countHelper(vector<int> &arr, vector<int> &temp, int left, int right) {
	int mid;
	long invCount = 0;

	if (left < right) {
		mid = left + (right - left) / 2;

		invCount += countHelper(arr, temp, left, mid);
		invCount += countHelper(arr, temp, mid + 1, right);

		invCount += merge(arr, temp, left, mid + 1, right);
	}

	return invCount;
}

long countInversions(vector<int> arr) {
	vector<int>temp(arr.size());
	return countHelper(arr, temp, 0, arr.size() - 1);
}




/*

Method 2 : Brute force                                      verdict : TLE

Complexity Analysis:

Time Complexity: O(N^2), Two nested loops are needed to traverse the array from start to end so the Time complexity is O(N*N).

Space Compelxity:O(1), No extra space is required.

*/



/*

Intution : -

Traverse through the array and for every index find the number of smaller elements on its right side of the array.
This can be done using a nested loop. Sum up the counts for all index in the array and print the sum.

*/