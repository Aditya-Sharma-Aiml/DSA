#include<bits/stdc++.h>
using namespace std;

//BruteForce :O(N)
pair<int,int>firstAndLastOccurance_bruteForce(vector<int>&arr, int x){
    int n = arr.size();

    int first = -1 , last = -1;
    for(int i=0 ; i<n ; i++){

        if(arr[i]==x){

            if(first == -1) first = i; // for first occurance
            last = i; // last upadte every time untill last fornd
        }
    }
    return {first , last};
}

// Implementation of lower bound and upper Bound: 2*O(logN)

pair<int,int>firstAndLastOccurance(vector<int>&arr, int x){
    int n = arr.size();

    int lb = lower_bound(arr.begin(),arr.end(),x) - arr.begin();
    int ub = upper_bound(arr.begin(),arr.end(),x) - arr.begin();

    if( lb==n || arr[lb] != x) return {-1,-1};
    return {lb , ub -1};
}

// Implementation of Binary Search from scratch

// case 1: find first
// case 2 : find last
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
pair<int , int> firstAndLastOccurance_binarySearch(vector<int>&nums , int x){

    int first = firstOccurance(nums,x);

    // if first not exit last never be exist
    if (first == -1) return {-1 , -1};
    
    int last = lastOccurance(nums, x);

    return {first , last};
}

// main 

int main(){
    int n ,x;
    cin >>  n >> x;
    vector<int>arr(n,0);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    pair<int,int> occurance = firstAndLastOccurance_binarySearch(arr, x);
    cout << "first :" << occurance.first <<endl;
    cout << "last :" << occurance.second <<endl;

}