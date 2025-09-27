#include <iostream>
#include <vector>
using namespace std;

//time :O(m+n) , space :O(1);
class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i = n - 1;       // nums1 ka last filled index
        int j = m - 1;       // nums2 ka last index
        int k = n + m - 1;   // nums1 ka last total index

        while(i >= 0 && j >= 0) {

            // nums1 ka element bada ho
            if(nums1[i] >= nums2[j]) {

                nums1[k] = nums1[i];
                i--;

            } 
            // nums 2 ka element bada ho
            else {

                nums1[k] = nums2[j];
                j--;
            }

            k--;
        }
        // Agar nums2 me abhi bhi elements bache hain
        while(j >= 0) {
            nums1[k] = nums2[j];
            j--;
            k--;
        }
        // Agar nums1 me bache hain to wo already sahi jagah pe hain
    }
};

int main() {
    int n, m;
    // cout << "Enter size of nums1 (with extra space) and nums2: ";
    cin >> n >> m;

    vector<int> nums1(n + m);
    vector<int> nums2(m);

    // cout << "Enter " << n << " elements of nums1 (sorted): ";
    for(int i = 0; i < n; i++) {
        cin >> nums1[i];
    }

    // cout << "Enter " << m << " elements of nums2 (sorted): ";
    for(int i = 0; i < m; i++) {
        cin >> nums2[i];
    }

    Solution sol;
    sol.merge(nums1, n, nums2, m);

    cout << "Merged Array: ";
    for(int n : nums1) {
        cout << n << " ";
    }
    cout << endl;

    return 0;
}
