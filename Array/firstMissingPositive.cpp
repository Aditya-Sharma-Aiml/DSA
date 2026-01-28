#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n= nums.size();
        // apply cycle sort but "ignore the -ve" when sort
        // because ask is first missing +ve and "nums <= n"
        // after sorting start searching from "1 -> n"
        // if number is not found then answer is "n+1"
        int i=0;
        while(i<n){
            // use na kro wrna index : -ve ho gya toh overflow ho jayega
            // int correctIndx = nums[i]-1; 
            if(nums[i]>0 && nums[i] <= n && nums[i] != nums[nums[i]-1]){
                swap(nums[i], nums[nums[i]-1]);
            }
            else i++;
        }

        for(int i=0; i<n;i++){
            if(nums[i] != i+1) return i+1;
        }
        return n+1;
    }
};
int main(){
    int n;
    cin >> n;

    vector<int>arr(n);
    for(int i=0; i<n ;i++){
        cin >> arr[i];
    }

    Solution sol;
    cout << sol.firstMissingPositive(arr);
}