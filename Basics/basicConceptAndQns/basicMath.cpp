#include<bits/stdc++.h>
using namespace std;

int countDigit(int n){
    int cnt = 0;

    // int cnt = log10(n) +1;

    while(n>0){
        cnt++;
        n/=10;
    }
    return cnt ;

}

int reverseNumber(int n){
    int rev = 0 ;
    while(n>0){
        int last_digit = n%10;
        rev= (rev*10)+last_digit;
        n/=10;
    }
    return rev;
}

bool isPalindrome(int n){
    
    int rev = reverseNumber(n);
    if(rev==n) return true;
    else false;

}

bool isArmstrong(int n){

    int total_digit = countDigit(n);
    int copy = n;
    int sum=0;

    while(n>0){
        int digit = n%10;
        sum+=pow(digit,total_digit);
        n/=10;
    }

    if(sum==copy) return true;
    else false;
}

int allDivisors(int n){
    // // brute force approach: o(n)

    // for(int i=1; i<=n ; i++){
    //     if (n%i==0) cout << i << " ";
    // }

    //optimized approach : o(sqrt(n))
    for(int i=1 ; i*i<=n ;i++){
        if (n%i==0){
            cout << i << " ";
            if((n/i)!=i){
                cout << n/i << " ";
            }
        }
    }
    cout<< endl;
    // example : 6
    // divisors: 1 6 2 3 
    // if you want sorted order then eithor store int array then sort it using sort funcn (sort take time (nlogn)) or use brute force approach

}

bool isPerfectNum(int n){

    if(n<=1) return false;
    int sum=1;

    for(int i=2 ; i*i<=n ;i++){
        if (n%i==0){
            sum+=i;
            if((n/i)!=i){
                sum+=(n/i);
            }
        }
    }
    if(n==sum) return true;
    else return false;
}

bool isPrime(int n){

    if(n<=1) return false;

    int count =0;

    for(int i=1 ; i*i<=n ;i++){
        if (n%i==0){
            count++;
            if((n/i)!=i){
                count++;
            }
        }
    }

    if(count==2) return true;
    else return false;
}

int main(){
    int n;
    cout << "enter the number";
    cin >> n;
    cout<<"count:";
    cout << countDigit(n) << endl;
    cout<<"reverse of "<< n << "is :";
    cout << reverseNumber(n)<< endl;
    cout << n << " ispalindrome : ";
    cout << isPalindrome(n)<< endl;
    cout << n << " isarmStrong : ";
    cout << isArmstrong(n)<< endl;
    cout << "All divisors of "<< n << "are :";
    allDivisors(n);
    cout << n << " isprime : ";
    cout << isPrime(n)<< endl;
    
}
