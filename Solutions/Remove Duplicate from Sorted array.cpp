/*

Method 1: fast and slow pointer            verdict : Accepted

Complexity analysis

Time complextiy : O(n). Assume that n is the length of array. Each of i and j traverses at most n steps.

Space complexity : O(1).

*/

int removeDuplicates(vector<int>& nums) {

    if (nums.size() == 0) {
        return 0;
    }

    int i = 1;

    for (int j = 1; j < nums.size(); j++) {
        if (nums[j] != nums[j - 1]) {
            nums[i] = nums[j];
            i++;
        }
    }
    return i;
}


/*

Method 2 : using Set               Verdict : Accepted

Complexity analysis

Time complextiy : O(n*log(n)). Assume n is length of array and and each operation cost log(n) time.

Space complexity : O(n).

*/

int removeDuplicates(vector<int>& nums) {
    set<int>noduplicate;

    for (int i = 0; i < nums.size(); i++) {
        noduplicate.insert(nums[i]);
    }

    nums.resize(0);

    for (auto it : noduplicate) {
        nums.push_back(it);
    }

    return noduplicate.size();

}