/*

Method 1 : Binary search                 Verdict : Accepted

Complexity Analysis :

Time Complexity : O(log(min(M,N))).

where M and N are the size of first and second array.

Space Complexity: O(1).

*/

/*

Key Idea : https://www.youtube.com/watch?v=uPqPDPjtPX4

we are partioning smaller array randomly and then finding a partion point for bigger array such that element at left side are smaller then element at right side and no of element at both side are equal in case of even size or 1 more if odd size.

*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);  //IF nums1 is not of minimum size just interchange arrays.
        }

        int lengthA = nums1.size();
        int lengthB = nums2.size();

        int minm = 0, maxm = lengthA;

        while (minm <= maxm) {

            int breakA = minm + (maxm - minm) / 2;
            int breakB = (lengthA + lengthB + 1) / 2 - breakA;

            int maxLeftA = breakA == 0 ? INT_MIN : nums1[breakA - 1];
            int minRightA = breakA == lengthA ? INT_MAX : nums1[breakA];

            int maxLeftB = breakB == 0 ? INT_MIN : nums2[breakB - 1];
            int minRightB = breakB == lengthB ? INT_MAX : nums2[breakB];

            if (maxLeftA <= minRightB && maxLeftB <= minRightA) {

                if ((lengthA + lengthB) % 2) {
                    return max(maxLeftA, maxLeftB);
                }
                else {
                    return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2.0;
                }
            }
            if (maxLeftA > minRightB) {
                maxm = breakA - 1;
            }
            else {
                minm = breakA + 1;
            }
        }

        return 0;

    }
}

/*

Method 2 : Two pointer merge method                 Verdict : Accepted

Complexity Analysis :

Time Complexity : O(M+N).

where M and N are the size of first and second array.

Space Complexity: O(1).


idea :- Merge both array using two pointer and extract median based of size of new merge sorted array even or odd.

*/


/*

Method 3 : Merge and sort(Brute force)                 Verdict : Accepted

Complexity Analysis :

Time Complexity : O((M+N)*Log(M+N)).

where M and N are the size of first and second array.

Space Complexity: O(1).


idea :- Concate both array and then sort the resultent array and then extract the median based on size even or odd.

*/