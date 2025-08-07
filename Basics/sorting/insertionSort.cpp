#include<bits/stdc++.h>
using namespace std;
// best-case : 1 2 3 4 5 -> o(n)
void insertionSort(int arr[],int n){
    
    for(int i=0 ; i<n ;i++){
         int j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
}
int main(){
    int n;
    cin >>n;
    int arr[n];
    for(int i =0 ;i <n ;i++){
        cin >> arr[i];
    }
    insertionSort(arr,n);
    for(int i =0 ;i <n ;i++){
        cout << arr[i] << " ";
    }

}
