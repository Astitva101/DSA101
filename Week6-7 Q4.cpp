/*Question:
You are given an integer array coins representing coins of different 
denominations and an integer amount representing a total amount of money.*/

#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int coinChange(std::vector<int>& coins, int amount) {
        // Create a dp array to store the minimum number of coins needed for each amount
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0; // Base case: no coins needed to make amount 0

        // Iterate over each coin and update the dp array
        for (int coin : coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }

        // If dp[amount] is still amount + 1, it means the amount cannot be made up with the given coins
        return dp[amount] > amount ? -1 : dp[amount];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * int param_1 = obj->coinChange(coins, amount);
 */