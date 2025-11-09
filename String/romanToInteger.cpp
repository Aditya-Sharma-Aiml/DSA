#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        
        unordered_map<char, int> values = {
        {'I', 1}, {'V', 5}, {'X', 10},
        {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int n = s.length();
        int result = 0;
        

        // Iterate through the string, except the last character
        for(int i=0 ; i<n-1 ; i++){
            // if ith < (i+1)th => means number become smaller
            // so subtract values[s[i]] from result.
            if(values[s[i]] < values[s[i+1]]){
                result -= values[s[i]];
            }
            // otherwise number become larger by adding
            else{
                result += values[s[i]];
            }
        }
        //The final character is always added
        // since there's nothing after it to compare.
        return result + values[s[n-1]]; 
    }
};

int main(){
    Solution sol;
    string s;
    cin >> s; // McL
    
    transform(s.begin(), s.end(), s.begin(),
    [](char ch){
        return toupper(ch);
    });
    // s.begin() (3rd): start of the output range (destination).
    // Using the same begin() here means you’re transforming in place (source and destination overlap starting at the same position).
    
    int num = sol.romanToInt(s);
    cout << num; // 1150
}