/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(k * 2^N).

where k is the average length of each possible solution. Copying such a possible solution list takes O(k) time.

Space Complexity: O(2^N).

Since each element is used only once (use it or not), intuitively we would say the size of the solution space is at most 2^N. Also, it can be interpreted as the sum of C(n, k) (which is 2^N) where k = 0...n is the size of the solution list.

If we do not consider the result list, the space complexity is bounded by O(N) because of at most N-size recursion stack and N-size of when copying list.



*/


void subset(vector<int>& candidates, vector<vector<int>>&solution, vector<int>&answer, int sum, int pos) {
	if (sum == 0) {
		solution.push_back(answer);
		return;
	}

	if (sum < 0) {
		return;
	}

	for (int i = pos; i < candidates.size(); i++) {
		answer.push_back(candidates[i]);
		subset(candidates, solution, answer, sum - candidates[i], i);
		answer.pop_back();
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	vector<vector<int>>solution;
	vector<int>answer;

	int n = candidates.size();

	subset(candidates, solution, answer, target, 0);

	return solution;

}


/*

Method : Backtracking              Verdict : Accepted


My solution based on Unbounded knapsack or we can say slight variation of coin change no of ways.


*/

void subset(vector<int>& candidates, vector<vector<int>>&solution, vector<int>&answer, int n, int sum) {
	if (sum == 0) {
		solution.push_back(answer);
		return;
	}

	if (n == 0 && sum != 0) {
		return ;
	}
	if (candidates[n - 1] <= sum) {
		answer.insert(answer.begin(), candidates[n - 1]);
		subset(candidates, solution, answer, n, sum - candidates[n - 1]);
		answer.erase(answer.begin());
		subset(candidates, solution, answer, n - 1, sum);
	}
	else {
		subset(candidates, solution, answer, n - 1, sum);
	}
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

	vector<vector<int>>solution;
	vector<int>answer;

	int n = candidates.size();

	subset(candidates, solution, answer, n, target);

	sort(solution.begin(), solution.end());

	return solution;

}