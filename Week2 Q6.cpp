/*Question:
Given a string S. The task is to print all unique permutations of the given string that may contain dulplicates in lexicographically sorted order. */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector> 
using namespace std;

class Solution {
public:
    void generatePermutations(string& S) {
        sort(S.begin(), S.end());
        
        vector<bool> used(S.length(), false);
        string perm = "";
        
        backtrack(S, perm, used);
    }
    
private:
    void backtrack(string& S, string& perm, vector<bool>& used) {
        if (perm.length() == S.length()) {
            cout << perm << endl;
            return;
        }
        
        for (int i = 0; i < S.length(); ++i) {
            if (used[i] || (i > 0 && S[i] == S[i-1] && !used[i-1])) {
                continue; // Skip used characters or duplicates at the same level
            }
            
            used[i] = true;
            perm.push_back(S[i]);
            backtrack(S, perm, used);
            perm.pop_back();
            used[i] = false;
        }
    }
};