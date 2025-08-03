#include<bits/stdc++.h>
using namespace std;

// uses ascii code
int hashArray(string s , char ch){
    // //prestoring (only for lower case)
    // int hash[26] = {0}; 
    // for(int i=0;i<s.size();i++){
    //     hash[s[i]-'a']++; // s[i]-'a' gives index b/w 0-25 : ex s[i]==b then 98-97 = 1 -->for b 
    // }
    // return hash[ch-'a'];

    // for all chars including symbol

    int hash[256] = {0};
    for(int i=0;i<s.size();i++){
         hash[s[i]]++; // s[i] ->auto converted into ASCII code
    }
    return hash[ch];
}
int main(){
   string s;
   cin>>s;
  // fetch
   int q;
   cin >> q;
    while(q--){
        char ch;
        cin >>ch;
        int count  = hashArray(s,ch);
        cout <<count << endl;    
    }


}