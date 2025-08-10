#include<bits/stdc++.h>
using namespace std;
void merge( vector<int>&arr,int low,int mid ,int high){

    vector<int>temp;
    int left = low;
    int right = mid+1;

    while(left <=mid && right <= high){
        if(arr[left]<=arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }
    while(left<=mid){
        temp.push_back(arr[left]);
            left++;
    }
    while(right<=high){
        temp.push_back(arr[right]);
        right++;
    }
    for(int i=low ;i<=high; i++) {
        arr[i]=temp[i-low]; 
        // we don't know what is low it can be updated furthor and furthor so The i - low part is there to align the indexes of arr and temp during the merge step.
    }

}
void merge_sort(vector<int>&arr, int low,int high){
    if(low>=high) return ;
    int mid = (low+high)/2;
    merge_sort(arr,low,mid);
    merge_sort(arr,mid+1,high);
    merge(arr,low,mid,high);
}
void mergeSort(vector<int>&arr,int n){
    merge_sort(arr,0,n-1);
}
int main (){
    int n;
    cin >> n;
    vector<int>arr;
    for(int  i=0 ;i<n ;i++){
        int e;
        cin >> e;
        arr.push_back(e);
    }
    mergeSort(arr,n);
    for(int i =0 ;i < n;i++){
        cout << arr[i] << " ";
    }


}
