/*

Complexity Analysis:-

Time Complexity : O(N*N).

Expected Auxilliary Space : O(N). To store output or final result.

*/

#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    string answer = "1";

    for (int i = 2; i <= n; i++) {
        string helper = "";

        for (int j = 0; j < answer.size(); j++) {
            int count = 1;

            while (j < answer.size() - 1 && answer[j] == answer[j + 1]) {
                count++;
                j++;
            }
            helper += to_string(count) + answer[j];
        }
        answer = helper;
    }
    return answer;
}

int main() {

    int n;
    cin >> n;

    cout << countAndSay(n) << endl;

    return 0;
}