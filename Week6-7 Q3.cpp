/*Question:
Given a m x n grid filled with non-negative numbers, find a path from top 
left to bottom right, which minimizes the sum of all numbers along its path.*/

#include <vector>
#include <algorithm>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }

        int m = grid.size();
        int n = grid[0].size();

        // Initialize the dp table with the same dimensions as the grid
        std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

        // Fill the dp table
        dp[0][0] = grid[0][0];

        // Fill the first row
        for (int j = 1; j < n; ++j) {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }

        // Fill the first column
        for (int i = 1; i < m; ++i) {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }

        // Fill the rest of the dp table
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }

        // The bottom-right cell contains the minimum path sum
        return dp[m - 1][n - 1];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * int param_1 = obj->minPathSum(grid);
 */