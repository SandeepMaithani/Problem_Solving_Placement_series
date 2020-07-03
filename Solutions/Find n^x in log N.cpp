
//Time Complexity O(Log(N)) and Space Complexity O(1)

// when n is positive

double ppow(double x, int n) {
    if (n == 0 || x == 1) {
        return 1;
    }
    if (n % 2 == 0) {
        double temp = myPow(x, n / 2);
        return temp * temp;
    }
    else {
        double temp = x * myPow(x, n - 1);
        return temp;
    }
}


// when n is negative

double npow(double x, int n) {

    if (n == 0 || x == 1) {
        return 1;
    }

    n = abs(n);

    if (n % 2 == 0) {
        double temp = myPow(1 / x, n / 2);
        return temp * temp;
    }
    else {
        double temp = (1 / x) * myPow(1 / x, n - 1);
        return temp;
    }
}

double myPow(double x, int n) {

    if (n == 0 || x == 1) {
        return 1;
    }

    if (n > 0) {
        return ppow(x, n);
    }
    else {
        return npow(x, n);
    }
}