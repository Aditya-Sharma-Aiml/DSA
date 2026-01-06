#include<bits/stdc++.h>
using namespace std;

void sayDigits(int n){

    if (n==0) return ;

    vector<string>say = {"zero","one","two","three", "four", "five", "six","seven","eight","nine"};

    int digit = n % 10;
    n /= 10;

    // cout << say[digit] << " ";  -> ye recrsn ke phle hua toh reverse me krega digit print

    sayDigits(n);

    // after recursion call print krne se jb call stack me funcn return hoga tb hoga 
    cout << say[digit] << " ";
}
int main(){
    int n ;
    cin >> n;
    sayDigits(n);
}