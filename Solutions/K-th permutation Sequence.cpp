/*

Method : Maths + pattern finding              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(n).

We will call our recursive function n times to find correct position of each n element.

Space Complexity: O(n+1).

For pre computation of factorials.

*/


void makeno(vector<int>&fact, vector<char>&nums, string &answer, int n, int k) {
	if (n <= 0) {
		return;
	}

	int ind = (k - 1) / fact[n - 1];
	k -= ind * (fact[n - 1]);

	answer += nums[ind];
	nums.erase(nums.begin() + ind);
	makeno(fact, nums, answer, n - 1, k);
}

string getPermutation(int n, int k) {

	vector<int>fact(n + 1, 1);
	vector<char>nums(n);
	string answer = "";

	for (int i = 1; i <= n; i++) {
		fact[i] = i * fact[i - 1];
		nums[i - 1] = i + '0';
	}

	makeno(fact, nums, answer, n, k);

	return answer;

}



/*

Method : Backtracking              Verdict : TLE

Complexity Analysis:

Time Complexity: O(n!).

Note that there are n! permutations so O(n!). And it requires O(n) time to print a permutation so if we print the permutation then it will become O(n*n!).

Space Complexity: O(n!). If we consider the solution vector to store all permutation

*/

void swap(string &answer, int first, int second) {
	char temp = answer[first];
	answer[first] = answer[second];
	answer[second]  = temp;
}

void store(vector<string>&solution, string &answer, int left, int right) {
	if (left == right) {
		solution.push_back(answer);
		return;
	}

	for (int mover = left; mover <= right; mover++) {
		swap(answer, left, mover);
		store(solution, answer, left + 1, right);
		swap(answer, left, mover);
	}
}
string getPermutation(int n, int k) {

	vector<string>solution;
	string answer = "";

	if (n == 0) {
		return answer;
	}

	if (n == 1) {
		return "1";
	}

	for (int i = 1; i <= n; i++) {
		string temp = to_string(i);
		answer += temp;
	}

	store(solution, answer, 0, n - 1);
	sort(solution.begin(), solution.end());

	return solution[k - 1];

}