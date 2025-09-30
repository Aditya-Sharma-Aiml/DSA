#include<bits/stdc++.h>
using namespace std;

//Brute Force :O(n^2)
int maxProductSubArray_BruteForce(vector<int>& nums) {
    int result = nums[0];
    for(int i=0;i<nums.size()-1;i++) {
        int p = nums[i];
        for(int j=i+1;j<nums.size();j++) {
           result = max(result,p);
           p *= nums[j];
        }
        result = max(result,p);//manages (n-1)th term 
    }
    return result;
}

// Optimal : O(N)

int maxProductSubArray(vector<int> &arr) {

    int n = arr.size(); 

    int pre = 1, suff = 1;
    int ans = INT_MIN;

    for (int i = 0; i < n; i++) {

        if (pre == 0) pre = 1;
        if (suff == 0) suff = 1;

        pre *= arr[i];
        suff *= arr[n - i - 1];

        ans = max(ans, max(pre, suff));
    }
    return ans;
}

//using kadan's Algo

int maxProductSubArray_Using_Kadans_Algo(vector<int>& nums) {
    int prod1 = nums[0],prod2 = nums[0],result = nums[0];
    
    for(int i=1;i<nums.size();i++) {
        int temp = max({nums[i],prod1*nums[i],prod2*nums[i]});
        prod2 = min({nums[i],prod1*nums[i],prod2*nums[i]});
        prod1 = temp;
        
        result = max(result,prod1);
    }
    
    return result;
}
int main()
{
    vector<int> arr = {1, 2, -3, 0, -4, -5};
    cout << "The maximum product subarray is: "
         << maxProductSubArray(arr) << "\n";
    return 0;
}
