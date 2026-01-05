#include<bits/stdc++.h>
using namespace std;

// Time: O(N*logN)

string numToBin(int num){ // logn

    string bin = "";

    while (num > 0){
        bin = char('0' + ( num & 1)) + bin;
        num /=2;
    }
    return bin;
    
}
void binaryUsingBitmanipulation(int n){ // n

    for (int i = 1; i <= n; i++)
    {
        string bin = numToBin(i);
        cout << bin << " " ;
    }
    
}
int main(){
    int n;
    cin >> n;
    binaryUsingBitmanipulation(n);
}