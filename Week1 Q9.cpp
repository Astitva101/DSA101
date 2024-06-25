/*Question:
You are given an array consisting of n integers which denote the position of a stall.
You are also given an integer k which denotes the number of aggressive cows. You are 
given the task of assigning stalls to k cows such that the minimum distance between any 
two of them is the maximum possible.
The first line of input contains two space-separated integers n and k.
The second line contains n space-separated integers denoting the position of the stalls.*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int solve(int n, int k, vector<int>& stalls) {
        sort(stalls.begin(), stalls.end());
        
        int left = 1; // Minimum possible distance
        int right = stalls.back() - stalls.front(); // Maximum possible distance
        int result = 0;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canPlaceCows(stalls, k, mid)) {
                result = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        return result;
    }
    
private:
    bool canPlaceCows(const vector<int>& stalls, int k, int distance) {
        int cowsPlaced = 1; // Place the first cow in the first stall
        int lastPosition = stalls[0];
        
        for (int i = 1; i < stalls.size(); ++i) {
            if (stalls[i] - lastPosition >= distance) {
                cowsPlaced++;
                lastPosition = stalls[i];
                if (cowsPlaced == k) {
                    return true;
                }
            }
        }
        
        return false;
    }
};