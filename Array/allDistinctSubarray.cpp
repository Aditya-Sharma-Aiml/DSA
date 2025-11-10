#include <bits/stdc++.h>
using namespace std;

// sliding Window 
vector<vector<int>> distinctSubarrays(vector<int> &arr) {
    int n = arr.size();
    unordered_map<int, int> freq;
    int left = 0;

    vector<vector<int>> result;

    for (int right = 0; right < n; right++) {

        freq[arr[right]]++;

        // shrink window when duplicate appears
        while (freq[arr[right]] > 1) {
            freq[arr[left]]--;
            left++;
        }

        // now window [left … right] is DISTINCT
        // generate all distinct subarrays ending at right
        // Number of SubArray = right - left + 1;
        for (int start = left; start <= right; start++) {
            vector<int> sub;
            for (int i = start; i <= right; i++) {
                sub.push_back(arr[i]);
            }
            result.push_back(sub);
        }
    }

    return result;
}

int main() {
    vector<int> arr = {1, 2, 1, 3};

    vector<vector<int>> ans = distinctSubarrays(arr);

    cout << "All distinct subarrays:\n";
    for (auto &sub : ans) {
        cout << "[ ";
        for (int x : sub) cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
