/*Question:
Given an integer array nums and an integer k,
 return the kth largest element in the array.

Note that it is the kth largest element in the 
sorted order, not the kth distinct element.*/

kth largest element in an array
#include <vector>
#include <queue>

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
        
        for (int num : nums) {
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        
        return minHeap.top();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * int param_1 = obj->findKthLargest(nums, k);
 */