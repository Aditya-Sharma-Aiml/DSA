#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int largestRectangleArea(vector<int> &heights) {
        int n = heights.size();
        stack<int> st;

        int pse[n], nse[n];

        // Compute Nearest Smaller to Left (NSL) for each bar
        for (int i = 0; i < n; i++) {
            // Pop until a smaller element is found or stack is empty
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller element on the left
            pse[i] = st.empty() ? -1 : st.top() ;

            // Push current index to stack
            st.push(i);
        }

        // Clear stack to reuse for NSR
        while (!st.empty()) st.pop();

        // Compute Nearest Smaller to Right (NSR) for each bar
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                st.pop();
            }

            // If stack is empty, no smaller to the right
            nse[i] = st.empty() ? n  : st.top();

            st.push(i);
        }

        // Calculate max area using NSL and NSR
        int maxA = 0;
        for (int i = 0; i < n; i++) {
            int width = nse[i] - pse[i]  - 1;
            maxA = max(maxA, heights[i] * width);
        }

        return maxA;
    }
};

class Solution2 {
  public:
    int largestRectangleArea(vector<int> &histo) {
        stack<int> st; // Stack to store indices of the histogram bars
        int maxA = 0;  // Variable to keep track of the maximum area
        int n = histo.size();

        // Loop through each bar including an imaginary bar at the end
        for (int i = 0; i <= n; i++) {
            // While current bar is smaller than the top of the stack or we reached the end
            while (!st.empty() && (i == n || histo[st.top()] >= histo[i])) {
                int height = histo[st.top()]; // Get the height of the bar at top of the stack
                st.pop(); // Remove that bar

                int width;
                if (st.empty()) {
                    width = i; // All bars before were higher
                } else {
                    width = i - st.top() - 1; // Width between current index and index at top of stack
                }

                // Calculate area and update maximum area
                maxA = max(maxA, width * height);
            }
            // Push current index into stack
            st.push(i);
        }
        return maxA;
    }
};


int main() {
    vector<int> heights = {2, 1, 5, 6, 2, 3, 1};
    Solution1 obj1;
    Solution2 obj2;

    // Output the largest area
    cout << "The largest area in the histogram is " << obj1.largestRectangleArea(heights) << endl;
    return 0;
}
