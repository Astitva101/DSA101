/*Question:
Given an integer array nums, return true if you can partition the array into two subsets such 
that the sum of the elements in both subsets is equal or false otherwise.*/

#include <vector>
#include <numeric>

class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // If the total sum is odd, it cannot be partitioned into two equal subsets
        if (totalSum % 2 != 0) {
            return false;
        }

        int target = totalSum / 2;
        int n = nums.size();
        
        // dp[i] will be true if a subset with sum i can be formed from the elements
        std::vector<bool> dp(target + 1, false);
        dp[0] = true;

        for (const int& num : nums) {
            for (int j = target; j >= num; --j) {
                dp[j] = dp[j] || dp[j - num];
            }
        }

        return dp[target];
    }
};
