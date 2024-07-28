/*Question:
Given a string s containing just the characters 
'(', ')', '{', '}', '[' and ']', determine if the input string is valid.*/

#include <stack>
#include <unordered_map>
#include <string>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        std::unordered_map<char, char> matchingBrackets = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };

        for (char ch : s) {
            if (matchingBrackets.count(ch)) {
                if (stack.empty() || stack.top() != matchingBrackets[ch]) {
                    return false;
                }
                stack.pop();
            } else {
                stack.push(ch);
            }
        }

        return stack.empty();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution();
 * bool param_1 = obj->isValid(s);
 */
