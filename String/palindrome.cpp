// You are given a string 'S'. Your task is to check whether the string is palindrome or not. For checking palindrome, consider alphabets and numbers only and ignore the symbols and whitespaces.

#include <bits/stdc++.h> 
using namespace std;
char checkType(char x){
    if (x >= '0' && x <='9') return 'n';
    else if (( x >= 'a' && x<= 'z') || ( x >= 'A' && x<= 'Z')) return 'c';
    else return 'i';

}
bool checkPalindrome_fromScratch(string s)
{
    int i = 0, j = s.size() - 1;
    while(i < j){
        // other
        while(i<j && checkType(s[i])=='i') i++;
        while(i<j && checkType(s[j])=='i') j--;

        char x = checkType(s[i]);
        char y = checkType(s[j]);

        char left = (x=='c' ? tolower(s[i]) : s[i]);
        char right = (y=='c' ? tolower(s[j]) : s[j]);
        if(left != right) return false;
        i++;
        j--;
             

    }
    return true;
}

// xxxxxxxxxxxx use functions xxxxxxx
bool checkPalindrome(string s){
    int i=0 , j=s.size()-1;
    while(i<j){
        
        while(i<j && !isalnum(s[i])) i++;
        while(i<j && !isalnum(s[j])) j--;

        if(tolower(s[i]) != tolower(s[j])) return false;
        i++;
        j--;

    }
    return true;
}
int main(){
    string s;
    getline(cin , s);
    cout << checkPalindrome(s) << endl;
    cout << checkPalindrome_fromScratch(s) << endl;

}