#include<bits/stdc++.h>
using namespace std;

string removeDuplicate(string &s)
{
    // Write your code here
    string res ="";
    for(int i = 0 ; i<s.size() ; i++){
        
        if(i==0 || s[i] !=s[i-1]){
            res+=s[i];
        }
        
    }
    return res;
}
int main(){
    string str ;
    getline(cin,str);
    cout << removeDuplicate(str);

}