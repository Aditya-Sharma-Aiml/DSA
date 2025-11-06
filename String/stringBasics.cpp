#include<iostream>
using namespace std;
bool isNum(char ch){
    return (ch >='0' && ch <='9') ;
}
bool isChar(char ch){
    return ((ch >= 'a' && ch <= 'z') ||(ch >= 'a' && ch <= 'z'));
}
char getLower(char ch){

    if(isChar(ch)) return (ch - 'A' + 'a'); // uper to lower
    else return ch;
}
char getUpper(char ch){

    if(isChar(ch)) return (ch - 'a' + 'A'); // lower to upper
    else return ch;
}
int main(){
    string s;
    getline(cin , s);
}