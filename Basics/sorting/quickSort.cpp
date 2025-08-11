#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>&arr ,int low ,int high){

    int pivot = arr[low];
    int i=low;
    int j=high;

    while(i<j){

        while( arr[i] <= pivot && i<=high-1 ){ // i<= high-1 : kyonki i array ke bahar na chli jaye
            i++; // searching larger to moving right 
        }
         while( arr[j] >= pivot && j>= low+1){
            j--; // searching smaller to moving left 
        }
        if(i<j){
            swap(arr[i],arr[j]);
        }
    }
    // pace pivot in its correct postuion in sorted array
    swap(arr[j],arr[low]);
    return j;


}
void quickSort(vector<int>&arr,int low,int high){
    if (low<high){
        int partition_index = partition(arr,low,high);
        quickSort(arr,low,partition_index-1);
        quickSort(arr,partition_index+1,high);
    }
    
    
}
int main(){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i=0 ;i<n ;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    quickSort(arr,0,n-1);
    for(int i=0 ; i<n ;i++){
        cout << arr[i] << " ";
    }
}