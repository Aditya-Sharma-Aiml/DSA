#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// prefered go for Kadan's Algorithm for optimal

int maximumSubarraySum(vector<int> &arr){

    int n = arr.size();
    int maxi = INT_MIN;

    for(int i = 0 ; i< n ; i++){

        int sum = 0;
        
        for(int j = i ; j <n ;j++){
            sum+=arr[j];
            maxi = max(sum , maxi);
        }

    }
    return max(0 , maxi); // handled when sum of subarray exist as -ve

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
    cout << maximumSubarraySum(arr);
}