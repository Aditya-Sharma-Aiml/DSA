#include<bits/stdc++.h>
using namespace std;
// push max at last by swaping adjacent 
void bubbleSort(int arr[],int n){
    int run=0;
    for(int i=n-1 ; i>=1 ; i--){

        int did_swap =0;  // optimal o(n) -> best case

        for(int j=0 ;j <=i ; j++){

            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                did_swap = 1;
            }
        }
        
        if(did_swap==0) break;
        
    }
}
int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i =0 ;i <n ;i++){
        cin >> arr[i];
    }
    bubbleSort(arr,n);
    for(int i =0 ;i <n ;i++){
        cout << arr[i] << " ";
    }

}
