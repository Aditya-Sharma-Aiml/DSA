#include<bits/stdc++.h>
using namespace std;

//Time: O(N)
//Space: O(1)
int myAtoi(string s) {
    
    int n = s.length();
    // 1-> skip leading spaces
    int i=0;
    while(i<n && s[i] == ' ') i++;

    //2->determine sign and move to next char
    int sign = 1;
    if(s[i] == '-'){
        sign = -1 ;
        i++;
    }
    else if(s[i] == '+') i++;

    // if non-digit found(all are spaces) return 0
    if(i == n) return 0;

    long long  ans = 0;

    //3-> read all digit untill we get non-digit
    while(i<n && isdigit(s[i])){

        ans = ans * 10 + (s[i] - '0');

        //4-> overflow/underflow:

        //if ans > INT_MAX : OVERFLOW OCCUR
        if (i<n && ans > INT_MAX) return INT_MAX;
        //if ans < INT_MIN : UNDERFLOW OCCUR
        if (i<n && ans < INT_MIN ) return INT_MIN;

        i++;
    }
    return (int)(sign * ans);
}
int main(){
    string s; //   "    -042ad jdb-"
    getline(cin, s);
    int num = myAtoi(s);
    cout << num;
}