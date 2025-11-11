#include <bits/stdc++.h>
using namespace std;

//Time : O(n ^ 2)
// not recommend this so use memorization 
class Solution {
public:
    bool isPalindrome(string s, int left, int right){

        while(left <= right){
            if( s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    string longestPalindrome_BruteForce(string s) {
        // because 1 <= s.length <= 1000 so we can do without DP
        int n = s.length();

        int startPoint = 0;
        int maxLen = INT_MIN;

        // generate all substring
        for(int i=0 ; i<n ; i++){

            for(int j=i ; j<n ; j++){

                // check each substring palindome or not
                if(isPalindrome(s,i,j)){
                    // if palindome then keep track of starting point
                    // ans also length of that substring
                    int len = j - i + 1;
                    if(len > maxLen){
                        maxLen = len;
                        startPoint = i;

                    }
                }
            }
        }
        return s.substr(startPoint, maxLen);

    }

    // xxxxxxxxxxxxxxxxxxxxxxxx Better xxxxxxxxxxxxxxxxxxxxxx
    string longestPalindrome(string str) {
        int start = 0, end = 0;

        // Iterate through each character as center
        for (int center = 0; center < str.length(); center++) {
            // Expand around odd length palindrome
            int lenOdd = expandFromCenter(str, center, center);
            // Expand around even length palindrome
            int lenEven = expandFromCenter(str, center, center + 1);
            // Get the max of both lengths
            int maxLen = max(lenOdd, lenEven);

            // Update the longest palindrome boundaries
            if (maxLen > end - start) { //(end - start + 1))
                start = center - (maxLen - 1) / 2; 
                end = center + maxLen / 2;
            }
        }

        // Return the longest palindromic substring
        return str.substr(start, end - start + 1);
    }

private:
    int expandFromCenter(const string& str, int left, int right) {
        // Expand while characters match and within bounds
        while (left >= 0 && right < str.length() && str[left] == str[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome
        return right - left - 1;
    }
};

int main(){
     Solution sol;
    string input = "babad";
    cout << "Longest Palindromic Substring: " << sol.longestPalindrome(input) << endl;
    return 0;
}