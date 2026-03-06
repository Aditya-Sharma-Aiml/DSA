#include<bits/stdc++.h>
using namespace std;

class Solution1{  // total += min(leftmax, rigthMax) - height[i]
    
    //xxxxxxxx  time : O(3N), space : O(2N) xxxxxxxxxxxxxxxxx 
    public:
        int totalTrapped(vector<int>&height){

            int n = height.size();

            vector<int>prefixMax(n);
            vector<int>suffixMax(n);

            //prefix max of each element
            prefixMax[0] = height[0];
            for(int i=1; i<n ; i++){

                prefixMax[i] = max(prefixMax[i-1], height[i]);
            }

            //suffix max of each element
            suffixMax[n-1] = height[n-1];
            for(int i=n-2; i>=0 ; i--){

                suffixMax[i] = max(suffixMax[i+1], height[i]);
            }

            // calculate total unit of water trapped
            int total = 0;
            for(int  i=0; i<n; i++){

                int leftMax = prefixMax[i]; // curr prefix max
                int rightMax = suffixMax[i]; // curr suffix max

                total += min(leftMax, rightMax) - height[i];
                
            }
            return total;
        
        }

};
#include <bits/stdc++.h>
using namespace std;

class Solution2 {
public:
    // Function to calculate trapped rainwater using the optimal two-pointer approach
    int trap(vector<int>& height) {
        int n = height.size();
        
        // Initialize two pointers at both ends of the array
        int left = 0;
        int right = n - 1;
        
        // Variables to track the maximum height to the left and right
        int maxLeft = 0;
        int maxRight = 0;
        
        // Variable to store total trapped water
        int totalWater = 0;
        
        // Iterate until left pointer meets right pointer
        while (left <= right) {
            // If left bar is smaller or equal to right bar
            if (height[left] <= height[right]) {
                // If current left bar is higher than maxLeft, update maxLeft
                if (height[left] >= maxLeft) {
                    maxLeft = height[left];
                } else {
                    // Water trapped on left is difference between maxLeft and current height
                    totalWater += maxLeft - height[left];
                }
                left++; // Move left pointer to the right
            } else {
                // If current right bar is higher than maxRight, update maxRight
                if (height[right] >= maxRight) {
                    maxRight = height[right];
                } else {
                    // Water trapped on right is difference between maxRight and current height
                    totalWater += maxRight - height[right];
                }
                right--; // Move right pointer to the left
            }
        }
        
        // Return total trapped water
        return totalWater;
    }
};

int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    Solution1 sol1;
    Solution2 sol2;
    
    // Calculate trapped water
    int result1 = sol1.totalTrapped(height);
    int result2 = sol2.trap(height);
    
    cout << "Trapped Rainwater: " << result2 << endl;
    
    return 0;
}
