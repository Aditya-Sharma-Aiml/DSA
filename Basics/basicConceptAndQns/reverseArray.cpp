#include<bits/stdc++.h>
using namespace std;

void twoPointerReverseArray(vector<int> &arr1,int left ,int right){

    if(left>=right) return;

    swap(arr1[left],arr1[right]);

    twoPointerReverseArray(arr1,left+1,right-1);
}
void singlePointerReverseArray(vector<int> &arr2, int i,int n){

    if(i>=n/2) return;
    swap(arr2[i],arr2[n-i-1]);
    singlePointerReverseArray(arr2,i+1,n);

}
int main(){
    int n;
    cout<<"Enter size of array: ";
    cin>> n;
    vector<int>arr1(n);
    for(int i=0 ; i<n ;i++){
        cin >> arr1[i];
    }
    vector<int>arr2 = arr1;
    
    twoPointerReverseArray(arr1,0,n-1);
    for(int a : arr1){
        cout << a<< " ";
    }
    cout << endl;
    singlePointerReverseArray(arr2,0,n);
    for(int a : arr2){
        cout << a<< " ";
    }
    
}