/*Question:
Given an array/list of length ‘n’, where the array/list represents the boards and each element of the given array/list represents 
the length of each board. Some ‘k’ numbers of painters are available to paint these boards. Consider that each unit of a board
 takes 1 unit of time to paint.
You are supposed to return the area of the minimum time to get this job done of painting all the ‘n’ boards under a constraint 
that any painter will only paint the continuous sections of boards.*/

#include <vector>
#include <numeric>
using namespace std;

bool canPaintAll(vector<int>& boards, int k, long long maxTime) {
    int painters = 1;
    long long currentSum = 0;
    
    for (int i = 0; i < boards.size(); ++i) {
        if (currentSum + boards[i] > maxTime) {
            painters++;
            currentSum = boards[i];
            if (painters > k) {
                return false;
            }
        } else {
            currentSum += boards[i];
        }
    }
    
    return true;
}

int findLargestMinDistance(vector<int>& boards, int k) {
    long long left = *max_element(boards.begin(), boards.end());
    long long right = accumulate(boards.begin(), boards.end(), 0LL); // Accumulate total sum of boards
    long long result = right; // Initialize result with maximum possible value
    
    while (left <= right) {
        long long mid = left + (right - left) / 2;
        
        if (canPaintAll(boards, k, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return (int)result;
}
