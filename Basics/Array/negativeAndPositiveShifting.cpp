#include<iostream>
#include<vector>
using namespace std;
// order does not matter
void moveNegativeLeftAndPositiveRight(vector<int>&arr, int n){
    int left = 0;
    int right = n-1;
    while(left<=right){
        if(arr[left]<0) left++;
        else if (arr[right]>=0) right--;
        else{
            swap(arr[left],arr[right]);
        }
    }

}
int main(){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i=0 ; i<n ; i++){
        int x;
        cin >>x;
        arr.emplace_back(x);

    }
    moveNegativeLeftAndPositiveRight(arr,n);
    for(auto num : arr){
        cout << num << " ";
    }

}