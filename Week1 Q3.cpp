/* Question:
Given an integer array nums of length n where all the integers of nums are in the range [1, n]
 and each integer appears once or twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant extra space.*/

#include <vector>
#include <cmath> 
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> duplicates;
        
        for (int i = 0; i < nums.size(); ++i) {
            int index = abs(nums[i]) - 1; 
            
            if (nums[index] < 0) {
                duplicates.push_back(abs(nums[i]));
            } else {
                nums[index] = -nums[index];
            }
        }
        
        return duplicates;
    }
};