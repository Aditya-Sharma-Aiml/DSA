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
        vector<int> nseIdx(n);
        
        // Stack 
        stack<int> st;
        
        // Start traversing from the back
        for(int i = n - 1; i >= 0; i--) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the smaller element */
            while(!st.empty() && arr[st.top()] >= currEle){
                st.pop();
            }
            
            // Update the answer
            nseIdx[i] = !st.empty() ? st.top() : n;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return nseIdx;
    }
    
    /* Function to find the indices of 
    next greater elements */
    vector<int> findNGEidx(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> ngeIdx(n);
        
        // Stack 
        stack<int> st;
        
        // Start traversing from the back
        for(int i = n - 1; i >= 0; i--) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            element is not the greater element */
            while(!st.empty() && arr[st.top()] <= currEle){
                st.pop();
            }
            
            // Update the answer
            ngeIdx[i] = !st.empty() ? st.top() : n;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return ngeIdx;
    }
    
    /* Function to find the indices of 
    previous smaller or equal elements */
    vector<int> findPSEEidx(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> pseeIdx(n);
        
        // Stack 
        stack<int> st;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            elements are greater than the current element */
            while(!st.empty() && arr[st.top()] > currEle){
                st.pop();
            }
            
            // Update the answer
            pseeIdx[i] = !st.empty() ? st.top() : -1;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return pseeIdx;
    }
    
    /* Function to find the indices of 
    previous greater or equal elements */
    vector<int> findPGEEidx(vector<int> &arr) {
        
        // Size of array
        int n = arr.size();
        
        // To store the answer
        vector<int> pgeeIdx(n);
        
        // Stack 
        stack<int> st;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Get the current element
            int currEle = arr[i];
            
            /* Pop the elements in the stack until 
            the stack is not empty and the top 
            elements are smaller than the current element */
            while(!st.empty() && arr[st.top()] < currEle){
                st.pop();
            }
            
            // Update the answer
            pgeeIdx[i] = !st.empty() ? st.top() : -1;
            
            /* Push the index of current 
            element in the stack */
            st.push(i);
        }
        
        // Return the answer
        return pgeeIdx;
    }
    
    /* Function to find the sum of the 
    minimum value in each subarray */
    long long sumSubarrayMins(vector<int> &arr) {
        
        vector<int> nseIdx = findNSEidx(arr);
        
        vector<int> pseeIdx = findPSEEidx(arr);
        
        // Size of array
        int n = arr.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Count of first type of subarrays
            int left = i - pseeIdx[i];
            
            // Count of second type of subarrays
            int right = nseIdx[i] - i;
            
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            long long val = (freq*arr[i]*1LL);
            
            // Updating the sum
            sum += val;
        }
        
        // Return the computed sum
        return sum;
    }
    
    /* Function to find the sum of the 
    maximum value in each subarray */
    long long sumSubarrayMaxs(vector<int> &arr) {
        
        vector<int> ngeIdx = findNGEidx(arr);
        
        vector<int> pgeeIdx= findPGEEidx(arr);
        
        // Size of array
        int n = arr.size();
        
        // To store the sum
        long long sum = 0;
        
        // Traverse on the array
        for(int i=0; i < n; i++) {
            
            // Count of first type of subarrays
            int left = i - pgeeIdx[i];
            
            // Count of second type of subarrays
            int right = ngeIdx[i] - i;
            
            /* Count of subarrays where 
            current element is minimum */
            long long freq = left*right*1LL;
            
            // Contribution due to current element 
            long long val = (freq*arr[i]*1LL);
            
            // Updating the sum
            sum += val;
        }
        
        // Return the computed sum
        return sum;
    }
    
public:
    /* Function to find the sum of 
    subarray ranges in each subarray */
    long long subArrayRanges(vector<int> &arr) {
        
        // Return the result
        return ( sumSubarrayMaxs(arr) - 
                 sumSubarrayMins(arr) );
    }
};

int main() {
    vector<int> arr = {1, 2, 3};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to find the sum of 
    subarray ranges in each subarray */
    long long ans = sol.subArrayRanges(arr);
    
    cout << "The sum of subarray ranges is: " << ans;
    
    return 0;
}