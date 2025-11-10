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
    string longestPalindrome(string s) {
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
};