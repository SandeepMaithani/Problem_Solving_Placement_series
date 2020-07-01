
//Time Complexity O(N) & Space Complexity O(1)
//we use Two equation method to find two missing variable

void repeatedNumber(vector<int> &A) {

    long long int n = A.size();

    vector<int>answer;

    long long int sum = 0;
    long long int sqsum = 0;
    int rpt, miss;

    for (int i = 0; i < A.size(); i++) {
        sum += A[i];
        sqsum += (long long int)A[i] * A[i];
    }


    long long int totsum = (n * (n + 1)) / 2;
    long long int totsqsum = (n * (n + 1) * ((2 * n) + 1)) / 6;

    long long int eq1 = totsum - sum;
    long long int eq2 = totsqsum - sqsum;
    long long int eq3 = eq2 / eq1;

    miss = (eq1 + eq3) / 2;
    rpt = eq3 - miss;

    cout << rpt << " " << miss << endl;
}