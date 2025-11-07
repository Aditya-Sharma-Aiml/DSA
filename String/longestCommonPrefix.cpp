#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(N * log N + M)

// Space Complexity: O(M) -> as the ans variable can store the length of the prefix which in the worst case will be O(M).

class Solution {
public:
    // Returns the longest common prefix in a list of strings
    string longestCommonPrefix(vector<string>& str) {
        // Handle the case where input is empty
        if (str.empty()) return "";

        // Sort the strings lexicographically
        sort(str.begin(), str.end());

        // First string in sorted order
        string first = str[0];

        // Last string in sorted order
        string last = str[str.size() - 1];

        // To store the common prefix
        string ans = "";

        // Compare up to the length of the shorter string
        int minLength = min(first.size(), last.size());

        // Compare characters of first and last string
        for (int i = 0; i < minLength; i++) {
            // Stop if characters differ
            if (first[i] != last[i]) break;

            // Add matching character to answer
            ans += first[i];
        }

        // Return the longest common prefix
        return ans;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
    vector<string> strings = {"interview", "internet", "internal", "interval"};
    // vector<string>strings(n);
    // for(int i=0 ; i<n ; i++){
    //     cin >> strings[i];
    // }
    string longestPrefix = sol.longestCommonPrefix(strings);
    cout << "Longest Common Prefix: " << longestPrefix << endl; 



}