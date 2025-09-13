#include<bits/stdc++.h>
using namespace std;

// better approach : count 0's , 1's , 2's
void sort012(vector<int>&arr){

    int cnt0{}, cnt1 = 0, cnt2 = 0;
    int n= arr.size();

    for(int i=0 ;i<n ;i++){
        if(arr[i]==0) cnt0++;
        else if(arr[i]==1) cnt1++;
        else cnt2++;
    }

    for(int i=0 ;i<cnt0 ;i++){
        arr[i]=0;
    }

    for(int i=cnt0 ;i<cnt0+cnt1 ;i++){
        arr[i]=1;
    }
    
    for(int i=cnt0+cnt1;i<n ;i++){
        arr[i]=2;
    }

}
// optimal approach : Dutch National Flag Algorithm 
void sort012s(vector<int>&arr){

    int n = arr.size();
    int low = 0 , mid = 0 , high = n-1;

    while(mid<=high){

        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            low++;
            mid++;
        }

        else if(arr[mid]==1){
            mid++;
        }

        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
}
int main(){
    int n ;
    cin >> n ;
    vector<int> arr;
    for(int i=0 ;i<n ;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    // sort012(arr);
    sort012s(arr);
    for(auto num : arr){
        cout << num << " ";
    }

}