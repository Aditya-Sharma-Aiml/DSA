#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;

string reverseWords_UsingTokenization(string s){

    stringstream ss; // tokenizer
    ss << s; //stringstream ss(s); 

    string token = "";
    string ans = "";

    while(ss >> token){ // token extraction : token example -> boy
        ans = token +" "+ ans; // boy a am i ""
    }
    //substr(sytarting index , no. of chars);
    ans = ans.substr(0,ans.size()-1); // if(!ans.empty()) ans.pop_back();
    return ans;

}
string reverseWords(string s) {

    int n = s.size();
    string ans = "";

    //1 -> reverse entire string
    reverse(s.begin(), s.end());

    for(int i=0 ; i<n ; i++){

        string word = "";

        while(i<n && s[i] != ' '){ // internal multiple spaces handled autometically
            word += s[i];
            i++;
        }
        //2-> reverese each words
        reverse(word.begin(), word.end());

        if(word.size() > 0){
            ans += " "+ word; 
        }

    }
    return ans.substr(1); // skip 1st char that is space
}
int main(){
    string s; //"i am a boy ";
    getline(cin , s);
    cout << "Actual string :" << s << endl;
    cout << "String after reversing Words :" << reverseWords(s); 
}