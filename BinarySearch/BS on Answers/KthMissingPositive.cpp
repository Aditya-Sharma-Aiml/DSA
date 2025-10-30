#include <bits/stdc++.h>
using namespace std;

// brute Force : O(N)
// Note: The main idea is to shift k by 1 step if the current element is smaller or equal to k. And whenever we get a number > k, we can conclude that k is the missing number.
int kthmissing(vector<int>nums , int k){
    
    for(int num : nums){
        if (num <= k) k++; //shifting k
        else break;
    }
    return k;
}


// Optimal : BS
//Time Complexity: O(logN)

int kthMissing(vector<int>&nums ,int k){

    // step 1 : figure out two nearest indices where the number can lie by the help of ideal array num and no. of missing upto that index(minimum range where can number exist)

    int low = 0 , high = nums.size()-1;
    while(low <= high){
            int mid = low + (high - low )/2;

            int missing = nums[mid] - (mid + 1); // (array_ele) - (idealy_arr_ele)
            if (missing < k) low = mid + 1;
            else high = mid - 1;
    }
    //range b/w:  high - low
    //step 2: find kth missing

    return low + k; // high + 1 + k;
}

int main(){
    int n ,k ;
    cin >> n >> k;
    vector<int>arr(n);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    cout << kthMissing(arr,k);
}
