#include <bits/stdc++.h>
using namespace std;

// Solution class to find next greater elements : O(N) space and time
class Solution1 {
public:
    // Function to find next greater elements
    vector<int> nextGreater(vector<int>& nums) {
        // Stack to store elements
        stack<int> st;

        // Result array of same size
        int n = nums.size();
        vector<int> res(n);

        // Traverse from right to left
        for (int i = n - 1; i >= 0; i--) {

            // Pop all smaller or equal elements
            while (!st.empty() && st.top() <= nums[i]) {
                st.pop();
            }

            // If stack is empty, no greater element
            if (st.empty()) res[i] = -1;

            // Else top of stack is the answer
            else res[i] = st.top();

            // Push current element
            st.push(nums[i]);
        }

        // Return the result
        return res;
    }
};

class Solution2 {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;   // element -> next greater
        stack<int> st;

        // Traverse nums2 from right to left
        for(int i = nums2.size() - 1; i >= 0; i--) {

            // Remove all smaller or equal elements
            while(!st.empty() && st.top() <= nums2[i])
                st.pop();

            // Store next greater element
            mp[nums2[i]] = st.empty() ? -1 : st.top();

            // Push current element into stack
            st.push(nums2[i]);
        }

        // Build answer for nums1
        vector<int> ans;
        for(int x : nums1)
            ans.push_back(mp[x]);

        return ans;
    }
};

int main() {

    Solution2 sol2;

    // Example Input
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};

    // Function Call
    vector<int> result = sol2.nextGreaterElement(nums1, nums2);

    // Output
    cout << "Next Greater Elements: ";
    for(int x : result)
        cout << x << " ";

    cout << endl;

    vector<int> nums = {4, 5, 2, 10};
    Solution1 sol1;
    vector<int> ans = sol1.nextGreater(nums);

    for (int x : ans) {
        cout << x << " ";
    }

    cout << endl;

}
