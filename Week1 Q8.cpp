/*Question:
Given a binary matrix M of size n X m. 
Find the maximum area of a rectangle formed only of 1s in the given matrix.*/

#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return 0;
        
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> heights(m, 0); // Heights array for histogram calculation
        int maxArea = 0;
        
        // Iterate through each row
        for (int i = 0; i < n; ++i) {
            // Update heights array for current row
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j] += 1;
                } else {
                    heights[j] = 0;
                }
            }
            
            // Calculate maximum area using heights array as histogram
            maxArea = max(maxArea, largestRectangleArea(heights));
        }
        
        return maxArea;
    }
    
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> s; // Stack to maintain indices of histogram bars
        int maxArea = 0;
        
        // Calculate maximum area using histogram approach
        for (int i = 0; i <= n; ) {
            int h = (i == n) ? 0 : heights[i];
            
            if (s.empty() || h >= heights[s.top()]) {
                s.push(i++);
            } else {
                int tp = s.top();
                s.pop();
                maxArea = max(maxArea, heights[tp] * (s.empty() ? i : i - s.top() - 1));
            }
        }
        
        return maxArea;
    }
};