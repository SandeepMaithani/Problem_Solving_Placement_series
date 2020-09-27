/*

Method 1 : Two Heaps                          Verdict : Accepted

Complexity Analysis:

Time Complexity: O(n Log n),

Time Complexity to insert element in min heap is log n. So to insert n element is O( n log n).

Space Complexity : O(n).

The Space required to store the elements in Heap is O(n) as we are storing all the elements in the heaps.

*/


/*

Intuition :-  we maintain two heaps in the following way:

1 . A max-heap to store the smaller half of the input numbers.
2 . A min-heap to store the larger half of the input numbers.

This gives access to median values in the input: they comprise the top of the heaps.

*/

class MedianFinder {
public:

    priority_queue<int>maxHeap;
    priority_queue<int, vector<int>, greater<int>>minHeap;


    void addNum(int num) {
        if (maxHeap.size() == 0 || maxHeap.top() > num) {
            maxHeap.push(num);
        }
        else {
            minHeap.push(num);
        }

        if (minHeap.size() > maxHeap.size() + 1) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        else if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
    }

    double findMedian() {
        if (minHeap.size() == maxHeap.size()) {
            int medianElement = minHeap.top() + maxHeap.top();
            return (medianElement * 0.5);
        }
        else if (minHeap.size() > maxHeap.size()) {
            return minHeap.top();
        }
        else {
            return maxHeap.top();
        }
    }
};


/*

Method 2 : Brute Force (Insertion Sort)                          Verdict : TLE

Complexity Analysis:

Time Complexity: O(N*N),

Since Insertion sort take O(N*N) time to sort element we can use binary search to find insertion point but we can't improve
the time taken to move element so it will take O(N^2) time.

Space Complexity : O(1).

The Space required to store the elements in Heap is O(n) as we are storing all the elements in the heaps.

*/


/*

Intuition :- If we can sort the data as it appears, we can easily locate median element.

*/

