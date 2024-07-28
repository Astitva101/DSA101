/*Question:
Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. 
You may assume all four edges of the grid are all surrounded by water.*/

#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        int numIslands = 0;

        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == '1') {
                    ++numIslands;
                    dfs(grid, i, j);
                }
            }
        }

        return numIslands;
    }

private:
    void dfs(std::vector<std::vector<char>>& grid, int i, int j) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        if (i < 0 || i >= numRows || j < 0 || j >= numCols || grid[i][j] == '0') {
            return;
        }
        
        grid[i][j] = '0'; // Mark the current cell as visited
        
        // Visit all four adjacent cells
        dfs(grid, i - 1, j); // Up
        dfs(grid, i + 1, j); // Down
        dfs(grid, i, j - 1); // Left
        dfs(grid, i, j + 1); // Right
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * int param_1 = obj->numIslands(grid);
 */