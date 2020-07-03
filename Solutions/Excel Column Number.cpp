int titleToNumber(string s) {

	int sum = 0;

	for (int i = 0; s[i]; i++) {
		sum = (26 * sum) + (s[i] - 'A' + 1);
	}

	return sum;

}