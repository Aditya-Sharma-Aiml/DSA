#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(n + k log k), where n is the length of the string and k is the constant 26 for the alphabet.

// Space Complexity: O(k) , where k is the constant 26 for the frequency array.

class Solution {
public:

    typedef pair<char,int>pairs; // <char , count of char>
    string frequencySort(string s) {

        // a-z : 97-122
        // A-Z : 65-90
        // 0-9 : 48-57
        vector<pairs> pairArr(123);
        // count freq of chars
        for(char ch : s){
            int freq = pairArr[ch].second;
            pairArr[ch] = {ch, freq+1};
        }
        // custom comparator(lambda function)
        auto comparator = [&](pairs p1, pairs p2){
                                return p1.second > p2.second;
        };
        
        sort(begin(pairArr),end(pairArr) , comparator);

        // resultant string
        string result = "";
        for(int i=0 ; i<123 ; i++){
            //if char present in string
            if(pairArr[i].second > 0){

                char ch = pairArr[i].first;
                int freq = pairArr[i].second;
                
                string temp = string(freq, ch);
                
                result += temp;
            }
        }
        return result;
    }
};

int main(){
    Solution sol;
    string s;
    getline(cin , s);
    string result = sol.frequencySort(s);
    cout << result;
}