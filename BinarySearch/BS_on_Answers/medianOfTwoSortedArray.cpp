#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // brute force
    // Time Complexity: O(N1+N2))
    // Space Complexity: O(N1+N2)
    double findMedianSortedArrays_bruteForce(vector<int>& nums1, vector<int>& nums2) {
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

        // Find median based on size
        int n = merged.size();
        if (n % 2 == 1)
            return merged[n / 2];
        else
            return (merged[n / 2 - 1] + merged[n / 2]) / 2.0;
    }

    // Better: 
    // Time Complexity: O(N1+N2)
    // Space Complexity: O(1)
    
    double findMedianSortedArrays_better(vector<int>& a, vector<int>& b) {

        // Get sizes of both arrays
        int n1 = a.size(), n2 = b.size();

        // Calculate total size
        int n = n1 + n2;

        // Calculate the middle indices
        int ind2 = n / 2;
        int ind1 = ind2 - 1;

        // Initialize pointers and counters
        int cnt = 0, i = 0, j = 0;
        int ind1el = -1, ind2el = -1;

        // Traverse both arrays like merge step of merge sort
        while (i < n1 && j < n2) {

            // Check which element is smaller and pick it
            if (a[i] < b[j]) {
                if (cnt == ind1) ind1el = a[i];
                if (cnt == ind2) ind2el = a[i];
                i++;
            } else {
                if (cnt == ind1) ind1el = b[j];
                if (cnt == ind2) ind2el = b[j];
                j++;
            }
            cnt++;
        }

        // Copy remaining elements from first array if any
        while (i < n1) {
            if (cnt == ind1) ind1el = a[i];
            if (cnt == ind2) ind2el = a[i];
            cnt++;
            i++;
        }

        // Copy remaining elements from second array if any
        while (j < n2) {
            if (cnt == ind1) ind1el = b[j];
            if (cnt == ind2) ind2el = b[j];
            cnt++;
            j++;
        }

        // Return median depending on even or odd size
        if (n % 2 == 1) return (double)ind2el;
        return (ind1el + ind2el) / 2.0;
    }

    //Optimal
    //time: O(min(log n , log m))

    double findMedianSortedArrays_optimal(vector<int>& nums1, vector<int>& nums2) {
        //O( min(logn, logm))
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        //BS on small array
        if(n1 > n2) return findMedianSortedArrays_optimal(nums2, nums1);

        int low = 0, high = n1;
        int left = (n+1)/2;//work for even and ood both -> To finding symmetry

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
                // median
                if(n%2==1){
                    return max(l1,l2);
                }
                else{
                    return (double)(max(l1, l2) + min(r1, r2)) / 2.0;
                }
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
    int n1, n2;
    cin >> n1 >> n2;

    vector<int> nums1(n1);
    vector<int> nums2(n2);

    for(int i=0 ; i<n1 ; i++){
        cin >> nums1[i];
    }
    for(int i=0 ; i<n2 ; i++){
        cin >> nums2[i];
    }
    cout << sol.findMedianSortedArrays_bruteForce(nums1, nums2) << endl;

    cout << sol.findMedianSortedArrays_better(nums1, nums2) << endl;

    cout << sol.findMedianSortedArrays_optimal(nums1, nums2) << endl;
    return 0;
}