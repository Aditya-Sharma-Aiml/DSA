#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// concept : Prefix Sum (Hashing)
// <<.............sum==s...............>>
// <-------sum==s-----> <-----sum==0---->

// time : o(n) , space : o(N)
int maxLenSubArrayWithZeroSum(vector<int>&arr){

    int n = arr.size();
    unordered_map<int,int> preSum; 
    int maxi = 0;
    int sum = 0; 
    // preSum[0] = -1; // edge case

    for(int i = 0;i<n;i++) {

        sum += arr[i]; 

        if(sum == 0) {
            maxi = i + 1; 
        }

        else {

            if(preSum.find(sum) != preSum.end()) {

                maxi = max(maxi, i - preSum[sum]); 
            }

            else {
                preSum[sum] = i;
            }

        }   
    }

    return maxi; 

}
int main(){
    int n ;
    cin >> n;
    vector<int>arr(n);
    for(int i =0 ; i< n ;i++){
        cin>>arr[i];
    }
    cout << maxLenSubArrayWithZeroSum(arr);
}
