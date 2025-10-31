
#include <bits/stdc++.h>
using namespace std;

int findDays(vector<int> &weights, int cap) {
    int days = 1; //First day.
    int load = 0;
    int n = weights.size(); 
    
    for (int i = 0; i < n; i++) {
        // cross the capacity of ship
        if (load + weights[i] > cap) {
            days += 1; //move to next day
            load = weights[i]; //load the weight.
        }
        else {
            //load the weight on the same day.
            load += weights[i];
        }
    }
    return days;
}


//Optimal: BS
//Time Complexity: O(N * log(sum(weights[]) - max(weights[]) + 1))

int leastWeightCapacity(vector<int> &weights, int d) {

    //Find the maximum and the summation:
    int low = *max_element(weights.begin(), weights.end());
    int high = accumulate(weights.begin(), weights.end(), 0);

    while (low <= high) {

        int mid = (low + high) / 2;

        int numberOfDays = findDays(weights, mid);

        if (numberOfDays <= d) {
            //eliminate right half
            high = mid - 1;
        }
        else {
            //eliminate left half
            low = mid + 1;
        }
    }
    return low;
}


//Brute Force: 
//Time Complexity: O(N * (sum(weights[]) - max(weights[]) + 1))

int leastWeightCapacity_BruteForce(vector<int> &weights, int d) {

    //Find the maximum and the summation:
    int maxi = *max_element(weights.begin(), weights.end());
    int sum = accumulate(weights.begin(), weights.end(), 0);

    for (int i = maxi; i <= sum; i++) {
        if (findDays(weights, i) <= d) {
            return i;
        }
    }
    //dummy return statement:
    return -1;
}

int main()
{
    vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    int d = 5;
    int ans = leastWeightCapacity_BruteForce(weights, d);
    cout << "The minimum capacity should be: " << ans << "\n";
    return 0;
}
