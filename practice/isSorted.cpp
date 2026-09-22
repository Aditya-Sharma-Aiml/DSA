#include<bits/stdc++.h>
using namespace std;
bool isSorted(int* arr, int size){

    if(size ==0 || size == 1) return true; // single size array is always sorted
    if(arr[0] > arr[1]) return false;
    else
        return isSorted(arr+1 , size-1);
}

int main(){

    int n;
    cin >> n;
    // dynamic array 
    int *arr = new int[n];
    
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cout << isSorted(arr, n);
}