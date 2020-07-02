
//GFG solution (rotate anticlockwise)
//Time Complexity O(N*N) and Space Complexity O(1)

void rotate(vector<vector<int>> &A) {

	int n = A.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int temp = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = temp;
		}
	}

	for (int j = 0; j < n; j++) {

		int fptr = 0, sptr = n - 1;

		while (fptr < sptr) {

			int temp = A[fptr][j];
			A[fptr][j] = A[sptr][j];
			A[sptr][j] = temp;

			fptr++;
			sptr--;
		}
	}
}

//Leetcode solution (Rotate clockwise)
//Time Complexity O(N*N) and Space Complexity O(1)

void rotate(vector<vector<int>>& matrix) {
	int n = matrix.size();

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			int temp = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = temp;
		}
	}

	for (int i = 0; i < n; i++) {

		int fptr = 0, sptr = n - 1;

		while (fptr < sptr) {

			int temp = matrix[i][fptr];
			matrix[i][fptr] = matrix[i][sptr];
			matrix[i][sptr] = temp;

			fptr++;
			sptr--;
		}
	}
}