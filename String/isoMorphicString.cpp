#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        
        unordered_map<char,char>map1;
        unordered_map<char,char>map2;

        int n = s.length(); // both has same length

        for(int i=0 ; i<n ; i++){

            char ch1 = s[i];
            char ch2 = t[i];

            // found in map but wrong matched => return false
            if (( map1.find(ch1) != map1.end() && map1[ch1] != ch2) || 
                (map2.find(ch2) != map2.end() && map2[ch2] != ch1)){
                return false;
            }
            // mapping
            map1[ch1] = ch2;
            map2[ch2] = ch1;
        }
        return true;
    }
};

int main() {
    Solution obj;

    string s, t;
    // cout << "Enter string s: ";
    cin >> s;

    // cout << "Enter string t: ";
    cin >> t;

    if(obj.isIsomorphic(s, t))
        cout << "Isomorphic\n";
    else
        cout << "Not Isomorphic\n";

    return 0;
}