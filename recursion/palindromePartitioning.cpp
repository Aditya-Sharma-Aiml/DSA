#include <bits/stdc++.h>
using namespace std;

// Complexity Analysis

// Time Complexity: O(2^N * N), we create all possible partitions and check whether they are palindrome or not.

// Space Complexity: O(2^N * N) + O(N), additional space used to store all possible results and auxiliary stack space.

class Solution {
public:
    // Function to check if substring s[start...end] is a palindrome
    bool isPalindrome(string &s, int start, int end) {
        
        while (start < end) {
           
            if (s[start] != s[end]) return false;
            
            start++;
            end--;
        }
        
        return true;
    }

    // Backtracking function to build partitions
    void backtrack(int index, string &s, vector<string> &path, vector<vector<string>> &res) {

        // If index reaches end of string, store current partition
        if (index == s.length()) {
            res.push_back(path);
            return;
        }

        // Try all possible substrings
        for (int i = index; i < s.length(); i++) {

            // If substring is a palindrome
            if (isPalindrome(s, index, i)) {

                // Add substring to current path : s.substr(startIdx, length_of_substr)
                path.push_back(s.substr(index, i - index + 1));

                // Recur for remaining string
                backtrack(i + 1, s, path, res);

                // Backtrack to try other partitions
                path.pop_back();
            }
        }
    }

    // Main function to return all palindrome partitions
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(0, s, path, res);
        return res;
    }
};


int main() {
    Solution sol;
    string s = "aabb";
    vector<vector<string>> ans = sol.partition(s);
    for (auto &vec : ans) {
        
        for (auto &str : vec)
            cout << str << " ";
        cout << endl;
    }
    return 0;
}
