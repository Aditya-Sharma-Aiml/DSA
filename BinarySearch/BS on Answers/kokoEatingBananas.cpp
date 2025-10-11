
#include <bits/stdc++.h>
using namespace std;

int findMax(vector<int> &v) {

    int maxi = INT_MIN;
    int n = v.size();
    
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly) {

    int totalH = 0;
    int n = v.size();
    //find total hours:
    for (int i = 0; i < n; i++) {

        totalH += ceil((double)(v[i]) / (double)(hourly)); // ceil => double
    }
    return totalH;
}

// Brute Force : Time Complexity: O(max(a[]) * N)

int minimumRateToEatBananas_BruteForce(vector<int> v, int h) {
    //Find the maximum number:
    int maxi = findMax(v);

    //Find the minimum value of k:
    for (int i = 1; i <= maxi; i++) {

        int reqTime = calculateTotalHours(v, i);

        if (reqTime <= h) {
            return i;
        }
    }

    //dummy return statement
    return maxi;
}


//Optimal: BS
// Time Complexity: O(N * log(max(a[]))), where max(a[]) is the maximum element in the array and N = size of the array.

int minimumRateToEatBananas(vector<int>& piles, int h) {
        
        int low = 1 , high = findMax(piles);
        
        while(low <= high ){

            int mid = low + (high - low)/2;
            int totalHours = calculateTotalHours(piles , mid);

            if(totalHours <= h) { //possible but  go for minimum rate(eliminate right)
                high = mid -1;
            }
            else{ // not possible so eliminate left
                low = mid + 1;
            }
            
        }
        return low;
    }

int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}