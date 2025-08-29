#include<bits/stdc++.h>
using namespace std;
int maximumConsecutiveOnes(vector<int>&nums){
    int count = 0;
        int maxi = 0;
        for(int i= 0; i<nums.size() ; i++){
            if(nums[i]==1){
                count++;
                maxi = max(count , maxi);
            }
            else{
                count = 0;

            }
        }
        return maxi;
}
int main (){
    int n;
    cin >> n;
    vector<int>arr;
    for(int i=0 ; i<n ; i++){
        int x ;
        cin >> x;
        arr.push_back(x);

    }
   int maxlen =  maximumConsecutiveOnes(arr);
    cout << maxlen;
}