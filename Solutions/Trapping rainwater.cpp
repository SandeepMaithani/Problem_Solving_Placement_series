/*

Method 1 :- Two Pointers        Verdict : Accepted

Complexity Analysis :

Time complexity: O(n) Single iteration of O(n).

Space complexity: O(1) extra space.

*/

int trap(vector<int>& height) {
    int n = height.size();
    int Wtrap = 0;

    if (n < 3) {
        return Wtrap;
    }

    int first = 0, second = n - 1;
    int lmax = height[first], rmax = height[second];

    while (first <= second) {
        lmax = max(lmax, height[first]);
        rmax = max(rmax, height[second]);

        if (lmax <= rmax) {
            Wtrap += lmax - height[first];
            first++;
        }
        else {
            Wtrap += rmax - height[second];
            second--;
        }
    }
    return Wtrap;
}


/*

Method 2 :- DP(Pre Computation of left bar and right bar)        Verdict : Accepted

Complexity analysis

Time complexity: O(n).

  We store the maximum heights upto a point using 2 iterations of O(n) each.
  We finally update ans using the stored values in O(n).

Space complexity: O(n+n) = O(n) extra Space.

  n extra space each for pre computing lmax and rmax.

*/

int trap(vector<int>& height) {

    int n = height.size();
    int Wtrap = 0;

    if (n <= 2) {
        return Wtrap;
    }

    vector<int>lmax(n);
    vector<int>rmax(n);

    lmax[0] = height[0];
    rmax[n - 1] = height[n - 1];

    for (int i = 1; i < n; i++) {
        lmax[i] = max(lmax[i - 1], height[i]);
    }

    for (int i = n - 2; i >= 0; i--) {
        rmax[i] = max(rmax[i + 1], height[i]);
    }

    for (int i = 0; i < n; i++) {
        Wtrap += min(lmax[i], rmax[i]) - height[i];
    }

    return Wtrap;
}

/*

Method 3 :- Brute force

Complexity Analysis :                   Verdict : TLE

Time complexity: O(n^2). For each element of array, we iterate the left and right parts.

Space complexity: O(1) extra space.

*/

int trap(vector<int>& height) {
    int n = height.size();
    int Wtrap = 0;

    for (int i = 0; i < n; i++) {

        int lmax = 0, rmax = 0;

        for (int j = 0; j <= i; j++) {
            lmax = max(lmax, height[j]);
        }

        for (int j = i; j < n; j++) {
            rmax = max(rmax, height[j]);
        }

        int ltrap = min(lmax, rmax) - height[i];

        Wtrap += ltrap;

    }

    return Wtrap;
}