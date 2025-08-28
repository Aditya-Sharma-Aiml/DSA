#include<iostream>
#include<vector>
using namespace std;
bool isSorted(int arr[] , int n){
    for(int i=1 ; i<n ;i++){

        if(arr[i]>arr[i-1]){
            
            // do nothing 
        }
        else{
            return false;
        }
    }
    return true;
}
int main (){
    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];

    }
    cout << isSorted(arr, n);
}