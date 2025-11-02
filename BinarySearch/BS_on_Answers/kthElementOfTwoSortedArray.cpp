#include <bits/stdc++.h>
using namespace std;

// xxxxxxxx same as median of two sorteed Array xxxxxxxx

class Solution {
public:
    // brute force
    // Time Complexity: O(N1+N2))
    // Space Complexity: O(N1+N2)
    double kthElement_bruteForce(vector<int>& nums1, vector<int>& nums2 , int k) {
        // Create a merged vector to store sorted elements
        vector<int> merged;
        
        // Initialize two pointers
        int i = 0, j = 0;
        
        // Merge both arrays in sorted order
        while (i < nums1.size() && j < nums2.size()) {

            // Push the smaller element into merged
            if (nums1[i] < nums2[j]) {
                merged.push_back(nums1[i]);
                i++;
            } else {
                merged.push_back(nums2[j]);
                j++;
            }
        }
        
        // Add remaining elements from nums1
        while (i < nums1.size()) {
            merged.push_back(nums1[i]);
            i++;
        }

        // Add remaining elements from nums2
        while (j < nums2.size()) {
            merged.push_back(nums2[j]);
            j++;
        }

        return merged[k - 1];
    }

    // Better: 
    // Time Complexity: O(N1+N2)
    // Space Complexity: O(1)
    
    double kthElement_better(vector<int>& a, vector<int>& b, int k) {

        // Get sizes of both arrays
        int n1 = a.size(), n2 = b.size();

        int ele = -1;
        int cnt = 0; //counter

        //apply the merge step:
        int i = 0, j = 0;

        while (i < n1 && j < n2) {
            if (a[i] < b[j]) {
                if (cnt == k - 1) ele = a[i];
                cnt++;
                i++;
            }
            else {
                if (cnt == k - 1) ele = b[j];
                cnt++;
                j++;
            }
        }

        //copy the left-out elements:
        while (i < n1) {
            if (cnt == k - 1) ele = a[i];
            cnt++;
            i++;
        }
        while (j < n2) {
            if (cnt == k - 1) ele = b[j];
            cnt++;
            j++;
        }
        return ele;
    }

    //Optimal
    //time: O(min(log n , log m))

    double kthElement_optimal(vector<int>& nums1, vector<int>& nums2, int k) {
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        //BS on small array
        if(n1 > n2) return kthElement_optimal(nums2, nums1, k);

        int low = max(0, k - n2), high = min(k, n1) ;
        int left = k;

        while(low <= high){
            
            int mid1 = low + (high - low)/2;
            int mid2 = left - mid1;

            int l1 = INT_MIN, l2 = INT_MIN; // if l1 or l2 not exist
            int r1 = INT_MAX , r2 = INT_MAX; // if r1 or r2 not exist

            if(mid1 < n1) r1 = nums1[mid1];
            if(mid2 < n2) r2 = nums2[mid2];

            if(mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
            if(mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

            if(l1 <= r2 && l2 <= r1){ // valid symmetry condition
                    return max(l1,l2); // kth-element 
      
            }
            else if (l1 > r2) { // eliminate right
                high = mid1 - 1;
            }
            else { // eliminate left
                low = mid1 + 1; 
            }

        }
        return 0;
        
    }

};

int main() {
    Solution sol;
    int n1, n2 ,k;
    cin >> n1 >> n2;
    cin >>k;

    vector<int> nums1(n1);
    vector<int> nums2(n2);

    for(int i=0 ; i<n1 ; i++){
        cin >> nums1[i];
    }
    for(int i=0 ; i<n2 ; i++){
        cin >> nums2[i];
    }
    cout << sol.kthElement_bruteForce(nums1, nums2 , k) << endl;

    cout << sol.kthElement_better(nums1, nums2, k) << endl;

    cout << sol.kthElement_optimal(nums1, nums2, k) << endl;
    return 0;
}