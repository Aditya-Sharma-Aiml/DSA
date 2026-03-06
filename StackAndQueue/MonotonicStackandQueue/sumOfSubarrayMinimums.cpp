#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    /* Function to find the indices of 
    next smaller elements */
    vector<int> findNSEidx(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> NSEidx(n);
        
        // Stack 
        stack<int> st;
        
        // Start traversing from the back
        for(int i = n - 1; i >= 0; i--) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the smaller element */
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            // Update the answer
            NSEidx[i] = !st.empty() ? st.top() : n;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return NSEidx;
    }
    
    /* Function to find the indices of 
    previous smaller or equal elements */
    vector<int> findPSEEidx(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> PSEEidx(n);
        
        // Stack 
        stack<int> st;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            elements are greater than the current element */
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            
            // Update the answer
            PSEEidx[i] = !st.empty() ? st.top() : -1;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return PSEEidx;
    }
    
public:

    /* Function to find the sum of the 
    minimum value in each subarray */
    int sumSubarrayMins(vector<int> &arr) {
        
        vector<int> nse = 
            findNSEidx(arr);
        
        vector<int> psee =
            findPSEEidx(arr);
        
        // Size of array
        int n = arr.size();
        
        int mod = 1e9 + 7; // Mod value
        
        // To store the sum
        int sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Count of first type of subarrays
            int left = i - psee[i];
            
            // Count of second type of subarrays
            int right = nse[i] - i;
            
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            int val = (freq*arr[i]*1LL) % mod;
            
            // Updating the sum
            sum = (sum + val) % mod;
        }
        
        // Return the computed sum
        return sum;
    }
};

int main() {
    vector<int> arr = {3, 1, 2, 4};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the sum of the 
    minimum value in each subarray */
    int ans = sol.sumSubarrayMins(arr);
    
    cout << "The sum of minimum value in each subarray is: " << ans;
    
    return 0;
}