
//Time Complexity O(log(N)) and Space complexity O(1)

int trailingZeroes(int n) {

	int count = 0;

	while (n > 0) {
		count = count + (n / 5);
		n = n / 5;
	}

	return count;

}