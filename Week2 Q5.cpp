/*Question:
Given an array of characters chars, compress it using the following algorithm:

Begin with an empty string s. For each group of consecutive repeating characters in chars:

If the group's length is 1, append the character to s.
Otherwise, append the character followed by the group's length.
The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.

After you are done modifying the input array, return the new length of the array.

You must write an algorithm that uses only constant extra space.*/

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        int write = 0; // pointer to write new characters
        int read = 0; // pointer to read characters
        int count = 1; // count of consecutive characters
        
        for (read = 0; read < n; ++read) {
            if (read + 1 < n && chars[read] == chars[read + 1]) {
                count++;
            } else {
                chars[write++] = chars[read]; // write current character
                
                if (count > 1) {
                    string countStr = to_string(count);
                    for (char c : countStr) {
                        chars[write++] = c; // write each digit of count
                    }
                }
                
                count = 1; // reset count for next character
            }
        }
        
        return write;
    }
};