//Method 1
//Time Complexity O(N) and Space Complexity O(1)

int maxProfit(vector<int>& prices) {

    int maxprofit = 0;

    int buyprice = INT_MAX;

    for (int i = 0; i < prices.size(); i++) {

        if (prices[i] < buyprice) {
            buyprice = prices[i];
        }
        else if ((prices[i] - buyprice) > maxprofit) {
            maxprofit = prices[i] - buyprice;
        }
    }

    return maxprofit;
}

//Method 2
//Time Complexity O(N*N) and Space Complexity O(1)

/*

brute force method can be applied to solve in which we will check profit for every possible
combination for max profit.

*/