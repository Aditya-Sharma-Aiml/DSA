#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // xxxxxxxxxxxxxx brute Force xxxxxxxxxxxxxxxxxxx

    // Time : O(N^2)
    // Space : O(N)

    // Check if 'goal' is a rotation of 's'
    bool rotateString_BruteForceI(string& s, string& goal) {
        // Strings must be same length to be rotations of each other
        if (s.length() != goal.length()) {
            return false;
        }
        // Try all possible rotations of 's'
        for (int i = 0; i < s.length(); i++) {

            string rotated = s.substr(i) + s.substr(0, i); 

            if (rotated == goal) {
                return true;
            }
        }
        return false;
    }

    // Time : O(N^2)
    // Space : O(1)

    bool rotateString_BruteForceII(string& s, string& goal){
        // Strings must be same length to be rotations of each other
        if (s.length() != goal.length()) {
            return false;
        }
        for(int i=0 ;i<s.length() ; i++){

            // rotate s by one place
            rotate(s.begin(), s.begin()+1, s.end());
            if(s==goal) return true;
        }
        return false;

    }

    // xxxxxxxxxxxxxx Optimal xxxxxxxxxxxxx
    // Time : O(N)
    // Space : O(N)

    bool rotateString(string &s , string &goal){
        
        int n = s.length();
        int m = goal.length();

        if(n != m) return false;
        
        // Concatenate s with itself and check if goal exists in it
        string TwiceOfS = s + s;

        // true if found otherwise false (npos -> positionn not found)
        return TwiceOfS.find(goal) != string::npos;
    }
};



int main() {
    Solution sol;
    string s = "rotation";
    string goal = "tionrota";
    
    // Output the result
    if (sol.rotateString(s, goal)) {
        cout << "true" << endl;  
    } else {
        cout << "false" << endl;
    }

    return 0;
}