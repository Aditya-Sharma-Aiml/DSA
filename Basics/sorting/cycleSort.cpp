#include<iostream>
#include<vector>
using namespace std;


void sort(vector<int>&arr){
    int n = arr.size();
    int i=0;
    //apply cycle sort 
    while(i<n){

        int correctIndx = arr[i]-1;
  
        if(arr[i] != arr[correctIndx]){

            swap(arr[i], arr[correctIndx]);
        }
        else i++;
    }

}

int main(){

    vector<int> arr = {4,0,2,1};

    sort(arr);
    for(int i=0; i<arr.size() ;i++){
        cout << arr[i] << " ";
    }
}