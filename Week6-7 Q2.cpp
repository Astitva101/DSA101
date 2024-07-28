/*Question:
Given an integer array nums, return the length of the longest strictly increasing 
subsequence*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        
        std::vector<int> dp(nums.size(), 1); // dp[i] represents the length of the LIS ending at index i
        int maxLength = 1;

        for (size_t i = 1; i < nums.size(); ++i) {
            for (size_t j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLength = std::max(maxLength, dp[i]);
        }

        return maxLength;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * int param_1 = obj->lengthOfLIS(nums);
 */