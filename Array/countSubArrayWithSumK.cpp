#include<bits/stdc++.h>
using namespace std;

// better => Time Complexity: O(N2)

int findAllSubarraysWithGivenSum(vector < int > & arr, int k) {
    int n = arr.size(); 
    int cnt = 0; 

    for (int i = 0 ; i < n; i++) { // starting index i
        int sum = 0;
        for (int j = i; j < n; j++) { // ending index j
            
            // sum of [i..j-1] + arr[j]
            sum += arr[j];

            
            if (sum == k)
                cnt++;
        }
    }
    return cnt;
}

//optimal => Time Complexity: O(N) or O(N*logN) depending on which map data structure we are using , space complexity : O(N)
int countSubArrayWithSumK(vector<int> &arr , int k){

    int n=arr.size();

    unordered_map<int,int>mpp;
    mpp[0]=1;
    int preSum = 0;
    int count = 0;

    for(int i=0 ;i<n ;i++){

        // add current element to prefix Sum:
        preSum += arr[i];

        // Calculate x-k:
        int remove = preSum - k;

        // Add the number of subarrays to be removed:
        count += mpp[remove];

        // Update the count of prefix sum  in the map
        mpp[preSum] += 1;
    }
    return count;

}
int main (){
    int n , k; 
    cin >> n >> k;
    vector<int> arr;
    for(int i=0 ; i<n ;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    cout << countSubArrayWithSumK(arr,k);
}