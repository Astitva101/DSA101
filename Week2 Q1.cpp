/*Question:
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.*/

#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.length() - 1;
        
        while (left < right) {
            // Move left pointer to next alphanumeric character
            while (left < right && !isAlphanumeric(s[left])) {
                left++;
            }
            // Move right pointer to previous alphanumeric character
            while (left < right && !isAlphanumeric(s[right])) {
                right--;
            }
            
            // Compare characters (ignore case)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            // Move pointers inward
            left++;
            right--;
        }
        
        return true;
    }
    
private:
    bool isAlphanumeric(char c) {
        return isalnum(c);
    }
};