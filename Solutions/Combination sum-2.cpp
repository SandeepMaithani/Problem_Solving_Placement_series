/*

Method : Backtracking              Verdict : Accepted

Complexity Analysis:

Time Complexity: O(k * 2^N).

where k is the average length of each possible solution. Copying such a possible solution list takes O(k) time.

Space Complexity: O(2^N).

Since each element is used only once (use it or not), intuitively we would say the size of the solution space is at most 2^N. Also, it can be interpreted as the sum of C(n, k) (which is 2^N) where k = 0...n is the size of the solution list.
If we do not consider the result list, the space complexity is bounded by O(N) because of at most N-size recursion stack and N-size of when copying list.

*/


void combination_helper(vector<int>&candidates, vector<vector<int>>&solution, vector<int>&answer, int target, int pos) {

	if (target == 0) {
		solution.emplace_back(answer);
		return;
	}
	if (target < 0) {
		return;
	}

	for (int mover = pos; mover < candidates.size() && target >= candidates[mover] ; mover++) {

		if (mover > pos && candidates[mover] == candidates[mover - 1]) {
			continue;
		}

		answer.emplace_back(candidates[mover]);
		combination_helper(candidates, solution, answer, target - candidates[mover], mover + 1);
		answer.pop_back();
	}

}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

	vector<vector<int>>solution;
	vector<int>answer;

	sort(candidates.begin(), candidates.end());

	combination_helper(candidates, solution, answer, target, 0);

	return solution;
}