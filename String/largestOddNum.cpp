
#include<bits/stdc++.h>
using namespace std;

// time : O(N)

class Solution {
public:
    // Returns the largest odd number substring from the given string
    string largeOddNum(string& s) {
        int ind = -1;

        // Find the last odd digit in the string
        
        for (int j = s.length() - 1; j >= 0; j--) {
            if ((s[j] - '0') % 2 == 1) {
                ind = j;
                break;
            }
        }

        // Skip leading zeroes up to the odd digit
        int i = 0;
        while (i <= ind && s[i] == '0') i++;

        // Return substring from first non-zero to odd digit
        return s.substr(i, ind - i + 1);
    }
};

int main() {
    Solution solution;
    string num = "0000504556385638544444000";
    string result = solution.largeOddNum(num);
    cout << "Largest odd number: " << result << endl;
    return 0;
}