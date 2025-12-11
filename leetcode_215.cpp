class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // Aint gon lie, its mad easy C a min-heap (smallest element on top)
        // We'll keep only k largest elements in it
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        // Go through each number in the array thats why I used num:nums cuz I need to compare with the number
        for (int num : nums) {
            // Add the current number to our heap
            minHeap.push(num);
            
            // If heap has more than k elements, remove the smallest
            // This keeps only the k largest elements in the heap
            if (minHeap.size() > k) {
                minHeap.pop();  // Remove the smallest (top of min-heap)
            }
        }
        
        // After processing all numbers, the heap has exactly k largest elements
        // The smallest of these k elements is the kth largest overall
        // And that's at the top of our min-heap!
        return minHeap.top();
        // When you have k elements in a heap, the tree has a height of log₂(k).
        //You only swap up the height = log k times maximum.
        // time complexity O(logK)
        //We process n elements (the size of nums)
        // For each element, we do a push (O(log k)) and maybe a pop (O(log k))
        // Total: O(n × log k)
    }
};
