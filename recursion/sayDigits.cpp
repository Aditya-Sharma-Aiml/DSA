#include<bits/stdc++.h>
using namespace std;

void sayDigits(int n){

    if (n==0) return ;

    vector<string>say = {"zero","one","two","three", "four", "five", "six","seven","eight","nine"};

    int digit = n % 10;
    n /= 10;
    sayDigits(n);
    
    cout << say[digit] << " ";
}
int main(){
    int n ;
    cin >> n;
    sayDigits(n);
}