#include <bits/stdc++.h>
using namespace std;

// approach  1
int missingElementA1(int arr[],int n){
    int XOR1 = 0 ,XOR2 = 0 ;
    for (int i=1 ; i<n ; i++){
        XOR1^=arr[i-1];
        XOR2^=i;
    }
    XOR2 ^=n;
    return XOR1 ^ XOR2;
}

// approach 2
int missingElementA2(int arr[],int n){
    int XOR1 = 0 ,XOR2 ;
    for (int i=0 ; i<n-1 ; i++){
        XOR1^=arr[i];
    }
    if (n%4==0) XOR2 = n;
    else if (n%4==1) XOR2 = 1;
    else if (n%4==2) XOR2 = n+1;
    else XOR2 = 0;

    return XOR1 ^ XOR2;
   
    
}

int main(){
    int n =7;
    int arr[]={1,3,5,6,7,4};
    int missing_element = missingElementA1( arr, n);
    // int missing_element = missingElementA2( arr, n);
    cout << "missing Element :" << missing_element << endl;

}