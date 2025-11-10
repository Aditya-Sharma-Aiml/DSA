#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMinPossible(vector<int>&nums ,int minPenalty,  int maxOps){

        int totalOps = 0;
        //Har element ko aise split karo ki saare bags ≤ final penalty ho jaye.
        for( int &num : nums){
            
            //it will give no. of operations to make minPenalty
            int ops = num / minPenalty;
            if( num % minPenalty == 0 ) ops -= 1;

            totalOps += ops;
            if(totalOps > maxOps) return false;
        }
        return true;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        
        int low = 1; // min penalty
        int high = *max_element(nums.begin(), nums.end()); //max penalty

        // BS on answers
        while(low <= high){
            int mid = low + (high - low) /2;

            if(isMinPossible(nums, mid, maxOperations)){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main(){
    int n; 
    cin >> n; //2
    int maxOperations;  //3
    cin >> maxOperations;
    vector<int>nums(n); // {9,8}
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    int minPenalty = sol.minimumSize(nums,maxOperations);
    cout << "Minimum possible Penalty would be: " << minPenalty; //4
    
}