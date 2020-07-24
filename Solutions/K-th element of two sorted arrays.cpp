/*

Method 1 : Basic Two Pointer approach                 Verdict : Accepted

Complexity Analysis :

Time Complexity : O(k).

Space Complexity: O(1).

*/

#include<bits/stdc++.h>
using namespace std;

int main() {

    int n, m, k;
    cin >> n >> m >> k;

    vector<int>first(n);
    vector<int>second(m);

    for (int i = 0; i < n; i++) {
        cin >> first[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> second[i];
    }

    int i = 0, j = 0;
    int answer;

    while (k--) {
        if (i < n && j < m) {
            if (first[i] <= second[j]) {
                answer = first[i];
                i++;
            }
            else {
                answer = second[j];
                j++;
            }
        }
        else if (i < n) {
            answer = first[i];
            i++;
        }
        else {
            answer = second[j];
            j++;
        }
    }

    cout << answer << endl;

    return 0;
}

/*

Method 2 : sorting

Complexity Analysis :

Time Complexity : O((n+m)*log(n+m)). Time require to sort new array of (n+m) no of element.

Space Complexity: O(n+m).


Key idea : store all the element from first and second array and finally sort them and extract the kth element from newly sorted array.

*/

