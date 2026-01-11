#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int start, int end, string &s) {
        while (start < end) {
            if (s[start++] != s[end--]) {
                return false;
            }
        }
        return true;
    }

    int findPartition(int idx, string &s) {
        if (idx == s.length()) return 0;

        int mini = INT_MAX;

        for (int i = idx; i < s.length(); i++) {

            if (isPalindrome(idx, i, s)) {

                int curr = 1 + findPartition(i + 1, s);
                mini = min(mini, curr);
            }
        }
        return mini;
    }

    int minCut(string s) {
        
        // minimum cuts = partitions - 1
        return findPartition(0, s) - 1;
    }
};

int main() {
    Solution obj;

    string s;
    cout << "Enter string: ";
    cin >> s;

    int result = obj.minCut(s);
    cout << "Minimum cuts required: " << result << endl;

    return 0;
}
