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
int main() {
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    
    Solution1 sol1;
    
    // Calculate trapped water
    int result = sol1.totalTrapped(height);
    
    cout << "Trapped Rainwater: " << result << endl;
    
    return 0;
}
