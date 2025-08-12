#include<bits/stdc++.h>
using namespace std;
// print all prime number till N
void primes(int n){

    vector<int>prime(n+1,1);

    for(int i=2 ; i*i<=n ;i++){

        if(prime[i]==1){
            
            for(int j=i*i ; j<=n ; j+=i){
                prime[j]=0;
            }
        }

    }
    for(int i=2 ; i<= n ;i++){
        if(prime[i]==1) cout << i << " ";
    }

}
int main(){
    int n;
    cin >> n;
    primes(n);
}