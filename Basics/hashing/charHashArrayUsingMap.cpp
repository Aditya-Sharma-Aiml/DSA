#include<bits/stdc++.h>
using namespace std;
// map-> have unique keys and always in sorted order (map<key_dataType,value_dataType>)
// unordered_map -> unique keys but not sorted
int intHashArray(string s,char ch){
    // prestore
    unordered_map<char,long long int>mpp;

    for(long long int i=0 ;i<s.size();i++){
        mpp[s[i]]++;
    }
    return mpp[ch];
}


int main(){
    string s;
    cin >> s;
    int q;
    cin >> q;
    // fetch
    while(q--){
        char ch;
        cin >> ch;
        int count = intHashArray(s,ch);
        cout<< count<<endl;

    }

}