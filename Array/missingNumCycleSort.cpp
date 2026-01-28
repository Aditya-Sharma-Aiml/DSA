#include<iostream>
#include<vector>
using namespace std;

// n distinct arr [0->n] : find missing

int missingNum(vector<int>  &arr , int n){

    int i=0;
    //apply cycle sort 
    while(i<n){

        int correctIndx = arr[i];
        // arr[i]<n -> handle if arr[i] is not in arr
        if(arr[i]<n && arr[i] != arr[correctIndx]){
            swap(arr[i], arr[correctIndx]);
        }
        else i++;
    }

    // case 1 if nums[i] != i : not at correct index return index
    for(int i=0; i<n ;i++){
        if (arr[i] != i) return i ;
    }
    //case 2: in nth is missing
    return n;

}

int main(){
    int n = 4;
    vector<int> arr = {4,0,2,1};

   cout <<  missingNum(arr,n);


}