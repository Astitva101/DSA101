/* Question:
Given an array/list 'ARR' of integers and a position ‘M’. You have to reverse the array after that position.

Example:

We have an array ARR = {1, 2, 3, 4, 5, 6} and M = 3 , considering 0 
based indexing so the subarray {5, 6} will be reversed and our 
output array will be {1, 2, 3, 4, 6, 5}.*/

 #include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void reverseArray(vector<int> &arr, int m) {
    // Ensure m is within the bounds of the array
    if (m < 0 || m >= arr.size()) {
        throw out_of_range("M must be within the bounds of the array indices");
    }
    
    // Reverse the subarray after position m
    reverse(arr.begin() + m + 1, arr.end());
}