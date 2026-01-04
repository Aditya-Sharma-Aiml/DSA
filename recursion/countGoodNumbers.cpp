#include<bits/stdc++.h>
using namespace std;

// time: o(logn)
// space : o(logn) -> stack 

class Solution {
public:
    const int MOD = 1e9 + 7; // to handle overflow

    long long power(long long x, long long n){
        
        if (n==0) return 1;
        if (n==1) return x;

        // power ka half and base ka square
        long long half = power(x,n/2) % MOD;
        long long pow = (half * half) % MOD;

        //if power odd aayi toh "x" ki multiply with pow
        if (n&1) pow = (pow * x) % MOD;
        return pow;
        

    }
    int countGoodNumbers(long long n) {

        //permutation : power(#even choice , #even indices) * power(#odd choice , #odd indices)

        // no. of even indices: (n+1)/2
        // no. of odd indices: (n)/2
         
        // total = power(5, (n+1)/2) * power(4,n/2);

        long long totalGood = power(5,(n+1)/2) * power(4,n/2) % MOD;
        return totalGood;
    }
};

int main(){
    Solution sol;
    int n;
    cin >> n;
   long long  totalGoodDigitString = sol.countGoodNumbers(n);
   cout << "total number of good digit string of length " << n << " is : " << totalGoodDigitString;
}