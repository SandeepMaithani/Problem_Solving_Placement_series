
/*

Complexity Analysis:

Time complexity : O(N) We traverse the list containing N elements only once. Each look up in the table costs only O(1) time.

Space complexity : O(N) The extra space required depends on the number of items stored in the hash table, which stores at most N elements.

*/

vector<int> twoSum(vector<int>& nums, int target) {
    vector<int>answer;
    unordered_map<int, int>hashmap;

    for (int i = 0; i < nums.size(); i++) {

        int second = target - nums[i];

        if (hashmap.find(second) != hashmap.end()) {
            answer.push_back(hashmap[second]);
            answer.push_back(i);

            return answer;
        }
        else {
            hashmap[nums[i]] = i;
        }
    }
    return answer;
}