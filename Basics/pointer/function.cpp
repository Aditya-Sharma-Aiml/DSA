#include<bits/stdc++.h>
using namespace std;
int sum(int arr[], int n){
    // C/C++ me agar aap array ko function me pass karte ho, to array decay ho jata hai "pointer" me.

    // yahaan arr actually "int* arr" ban jaata hai.
    // 👉 sizeof(arr) yahan sirf pointer size (4 ya 8) dega, array ke elements ka size nahi.

    cout << sizeof(arr)<< endl; // 4
    cout << sizeof(arr)/sizeof(arr[0])<< endl; //1

    int sum = 0;
    for(int i =0 ; i< n; i++){
        // sum+=i[arr];
        // sum+=arr[i];
        sum += *(arr+i);
    }
    return sum;
    
}
int main(){
    int arr[10] = {0,1,2,3,4,5,6,7,8,9};
    cout<< "SUM: " << sum(arr,10);
}