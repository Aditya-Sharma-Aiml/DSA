#include<bits/stdc++.h>
using namespace std;

int getSum(int* arr, int n){ // dyan rhe dynamic memory hai toh : int *arr
     
    int sum = 0;
    for(int i=0 ; i<n ; i++){
        sum+= arr[i];
    }
    return sum;
}
int main(){

    int n;
    cin >> n;

    // int arr[n]; // don't do this 

    int *arr = new int[n];

    for (int i=0 ; i<n ; i++){
        cin >> arr[i];
    }

    cout << getSum(arr, n);

   
}