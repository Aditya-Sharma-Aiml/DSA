#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextSmallerElement(vector<int>& arr) {
        int n = arr.size();

        // Stack to store potential previous smaller elements
        stack<int> st;

        // Answer array initialized with -1
        vector<int> ans(n, -1);

        // Traverse the array from left to right
        for (int i = 0; i<n ; i++) {

            // Pop elements from stack while they are >= current element
            while (!st.empty() && st.top() >= arr[i]) {
                st.pop();
            }

            // If stack is not empty, top is the previous smaller element
            if (!st.empty()) {
                ans[i] = st.top();
            }

            // Push current element to stack
            st.push(arr[i]);
        }

        // Return result
        return ans;
    }
};

int main() {
    vector<int> arr = {1, 3, 2, 4};
    Solution sol;

    // Get result
    vector<int> ans = sol.nextSmallerElement(arr);

    // Print result
    cout << "The next smaller elements are: ";
    for (int val : ans) {
        cout << val << " ";
    }

    return 0;
}