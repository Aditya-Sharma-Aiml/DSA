#include<bits/stdc++.h>
using namespace std;
// brute force (onnly for +ves)
int getLongestSubarray(vector<int>& a, long long k) {
    int n = a.size();
    int len = 0;

    for (int i = 0; i < n; i++) {
        long long s = 0; // har naye i ke liye sum reset karo
        for (int j = i; j < n; j++) {
            s += a[j];
            if (s == k) {
                len = max(len, j - i + 1);
            }
        }
    }

    return len;
}
// hashing (optimal for -ves abd +ves including zeros) 
int getLongestSubarrayHashing(vector<int>&arr , int k){

    map<long long , int > preSumMap;
    int n = arr.size();
    int maxLen = 0;
    long long sum= 0;

    for(int i=0 ; i<n ; i++){

        sum+=arr[i];

        if(sum==k) {
            maxLen = max(maxLen , i+1);
        }
        long long rem = sum - k;

        if(preSumMap.find(rem)!=preSumMap.end()){

            int len = i - preSumMap[rem];
            maxLen = max(maxLen,len);
        }
        if(preSumMap.find(sum)==preSumMap.end()){

            preSumMap[sum] =i;
        }

    }
    
    return maxLen;

}
// optimal for zero's and positives : two pointer approach
int getLongestSubarrayTwoPointer(vector<int>&arr , int k){
    
    int n = arr.size();
    int maxLen = 0;
    long long sum= arr[0];
    int left = 0 , right = 0;

    while(right<n){
        while(left <= right && sum > k){
            sum-=arr[left];
            left++;
        }
        if(sum==k) {
            maxLen = max(maxLen , right-left+1);
        }
        right++;
        if(right<n) sum+=arr[right];
    }
    return maxLen;

}
int main(){
    int n;
    long long k ;
    cin >> n >> k;
    vector<int> arr;
    for(int i = 0 ; i< n ; i++){
        int x;
        cin >>x ;
        arr.push_back(x);

    }
    // int maxLen= getLongestSubarray(arr, k);
    int maxLen = getLongestSubarrayHashing(arr,k);
    // int maxLen = getLongestSubarrayTwoPointer(arr,k);

    cout << maxLen;

}