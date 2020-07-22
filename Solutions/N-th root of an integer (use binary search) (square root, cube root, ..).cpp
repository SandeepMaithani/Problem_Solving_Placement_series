#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long int lli;

/*

In order to calculate nth root of a number, we can use the following procedure.

1. If x lies in the range [0, 1) then we set the lower limit low = x and upper limit high = 1, because for this range of numbers the nth root is always greater than the given number and can never exceed 1.
     eg-  sqrt(0.09) = 0.3.

2. Otherwise, we take low = 1 and high = x.

3. Declare a variable named epsilon and initialize it for accuracy you need.
   Say epsilon=0.01, then we can guarantee that our guess for nth root of the given number will be
   correct up to 2 decimal places.

4. Declare a variable guess and initialize it to guess=(low+high)/2.

5. Run a loop such that:

      5.1. If the absolute error of our guess is more than epsilon then do:
             a). if guessn > x, then high=x
             b). else low=x
             c). Making a new better guess i.e., guess=(low+high)/2.

      5.2. If the absolute error of our guess is less than epsilon then exit the loop.


Absolute Error: Absolute Error can be calculated as abs(pow(guess,n) -x).

*/

/*

Complexity Analysis :

Time Complexity: O(log(n)) Time taken for Binary search.

Space Complexity: O(1).

*/


double power(double x, int y)
{
	double temp;

	if (y == 0) {
		return 1;
	}

	temp = power(x, y / 2);

	if (y % 2 == 0) {
		return temp * temp;
	}
	else {
		return x * temp * temp;
	}
}

double rootBsearch(int x, int n) {
	double low, high;

	if (x >= 0 && x <= 1) {
		low = x;
		high = 1;
	}
	else {
		low = 1;
		high = x;
	}

	double accuracy = 0.00001;

	double testroot = (low + high) / 2;

	while (abs(power(testroot, n) - x) >= accuracy) {

		if (power(testroot, n) > x) {
			high = testroot;
		}
		else {
			low = testroot;
		}

		testroot = (low + high) / 2;
	}

	return testroot;
}


int main() {

	int x, n;

	cin >> x >> n;

	double answer = rootBsearch(x, n);

	cout << fixed << setprecision(5) << answer;

	return 0;
}


