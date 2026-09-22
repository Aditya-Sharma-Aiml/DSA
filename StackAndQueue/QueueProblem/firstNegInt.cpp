#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        
        deque<int> dq;
        vector<int> ans;
        int n = arr.size();

        // first window
        for(int i = 0; i < k; i++) {
            if(arr[i] < 0) dq.push_back(i);
        }

        ans.push_back(dq.empty() ? 0 : arr[dq.front()]);

        // sliding window
        for(int i = k; i < n; i++) {

            // remove out-of-window index
            if(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            // add current element
            if(arr[i] < 0) dq.push_back(i);

            // store answer
            ans.push_back(dq.empty() ? 0 : arr[dq.front()]);
        }

        return ans;
    }
};

int main() {
    Solution obj;

    vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
    int k = 3;

    vector<int> result = obj.firstNegInt(arr, k);

    cout << "First negative in every window: ";
    for(int x : result) {
        cout << x << " ";
    }

    return 0;
}