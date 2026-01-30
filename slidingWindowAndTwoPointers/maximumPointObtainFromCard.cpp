#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum=0, rsum=0, maxSum=0;

        for(int i=0; i<k; i++){
            lsum += cardPoints[i];
        }// take first left k element and initialize with max score

        maxSum = lsum;

        int rIndx = cardPoints.size()-1;
        for(int i=k-1; i>=0; i--){ 
            // now reduce left window size and increase right window size 
            lsum -= cardPoints[i];
            rsum += cardPoints[rIndx];
            rIndx = rIndx -1;

            maxSum = max(maxSum, lsum+rsum);
        }
        return maxSum; // maxScore
    }
};
int main() {
    // Example input
    vector<int> cards = {1, 2, 3, 4, 5, 6, 1};
    int k = 3;

    // Create object of Solution class
    Solution sol;

    cout << sol.maxScore(cards, k) << endl;

    return 0;
}