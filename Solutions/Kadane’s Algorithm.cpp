
//Time Complexity O(N) and Space Complexity O(1)

int maxSubArray(vector<int>& nums) {

    int answer = INT_MIN, sum = 0;

    for (int i = 0; i < nums.size(); i++) {
        sum = sum + nums[i];

        if (answer < sum) {
            answer = sum;
        }

        if (sum < 0) {
            sum = 0;
        }
    }
    return answer;
}