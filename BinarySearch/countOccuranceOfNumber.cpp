#include<bits/stdc++.h>
using namespace std;

//Approach 1 : implement lower bound and upper bound 
// count  = upper_bound(x) - lower_bound(x) 

int countOccurance(vector<int>&arr, int x){
    int n = arr.size();

    int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    int ub = upper_bound(arr.begin(),arr.end(),x) - arr.begin();

    if( lb==n || arr[lb] != x) return 0; // Number not found 
    int count = ub - lb;
    return count ;
}


//Approach 2 : implement simple binary search
// count = last - first + 1 

int firstOccurance(vector<int>&arr , int x){
    int n = arr.size();
    int low = 0 , high = n-1 ;
    int first = -1;

    while(low <= high){

        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            first  = mid;
            // go for more smaller index for x
            high = mid - 1; // only diff b/w first and last
        }
        else if (x > arr[mid]) low = mid + 1 ;
        else high = mid - 1;

    }
    return first;
}
int lastOccurance(vector<int>&arr , int x){
    int n = arr.size();
    int low = 0 , high = n-1 ;
    int last = -1;

    while(low <= high){

        int mid = low + (high - low)/2;
        if(arr[mid] == x){
            last  = mid;
            // go for more larger index for x
            low = mid + 1; // only diff b/w first and last
        }
        else if (x > arr[mid]) low = mid + 1 ;
        else high = mid - 1;

    }
    return last;
}
int countOccuranceOfNumber(vector<int>&nums , int x){

    int first = firstOccurance(nums,x);

    // if first not exit last never be exist
    if (first == -1) return 0;
    
    int last = lastOccurance(nums, x);

    int count = last - first + 1;
    return count ;
}
// main 
int main(){
    int n ,x;
    cin >>  n >> x;
    vector<int>arr(n,0);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    cout << countOccurance(arr,x) << endl;
    cout << countOccuranceOfNumber(arr,x) ;
    

}