
//Method 1 (without using seprate space)
//Time complexity O(N1 + N2) and Space Complexity O(1)

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    int fill = n + m - 1;
    int fst = m - 1;
    int sec = n - 1;

    while (fst >= 0 && sec >= 0) {
        if (nums1[fst] >= nums2[sec]) {
            nums1[fill] = nums1[fst];
            fill--;
            fst--;
        }
        else {
            nums1[fill] = nums2[sec];
            fill--;
            sec--;
        }
    }

    while (sec >= 0) {
        nums1[fill] = nums2[sec];
        fill--;
        sec--;
    }
}

//Method 2 (without using seprate space)
//Time complexity O(N1 + N2) and Space Complexity O(N1 + N2)

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int>sorted;
    int i = 0, j = 0;

    while (i != m && j != n) {
        if (nums1[i] <= nums2[j]) {
            sorted.push_back(nums1[i]);
            i++;
        }
        else {
            sorted.push_back(nums2[j]);
            j++;
        }
    }

    while (i != m) {
        sorted.push_back(nums1[i]);
        i++;
    }

    while (j != n) {
        sorted.push_back(nums2[j]);
        j++;
    }

    nums1 = sorted;

}