//GFG Problem
//Time Complexity O(N) and Space Complexity O(1)

#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int>stock(n);

        for (int i = 0; i < n; i++) {
            cin >> stock[i];
        }

        int pcount = 0;
        int start = 0;
        int end = 0;

        for (int i = 1; i < n; i++) {
            if (stock[i - 1] < stock[i]) {
                cout << "(" << i - 1 << " ";
                start = i - 1;
                i++;
                while (i < n) {
                    if (stock[i - 1] < stock[i]) {
                        i++;
                    }
                    else {
                        break;
                    }
                }
                end = i - 1;
                cout << i - 1 << ") ";
                pcount++;
            }
        }
        if (pcount == 0) {
            cout << "No Profit";
        }
        cout << "\n";
    }
    return 0;
}



//Leetcode Problem


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