#include <bits/stdc++.h>
using namespace std;


class Solution {
public:

    // all string mapping with digits
    unordered_map<char,string>digiLetters = {{'2' , "abc"},{'3' , "def"}, 
                                            {'4' , "ghi"},{'5' , "jkl"},
                                            {'6' , "mno"},{'7' , "pqrs"},
                                            {'8' , "tuv"},{'9' , "wxyz"}};

    void findCombination(int idx, string curr, string &digits, vector<string>&ans){
        // base case
        if(idx == digits.size()){
            ans.push_back(curr);
            return ;
        }
        char ch = digits[idx]; // num char
        string str = digiLetters[ch]; // string val corresponding to numchar

        // go for all possibility
        for(int i = 0 ; i < str.size() ; i++){
            
            curr.push_back(str[i]);
            findCombination(idx+1 , curr, digits, ans);
            curr.pop_back();     
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        
        findCombination(0, "", digits, ans);
        return ans;
    }
};

int main(){
    Solution sol;
    string digits;
    cin >> digits;

    vector<string>res = sol.letterCombinations(digits);

    for(string s: res){
        for(char ch : s){
            cout << ch;
        }
        cout << " ";
    }
}