#include <bits/stdc++.h>

using namespace std;

// Approach -1: using extra space => a freq array for marking and a data structure for storing

// Time Complexity:  N! x N
// Space Complexity:  O(N)

void recurPermute(vector<int>& nums, vector<int>& ds, vector<int>& freq, vector<vector<int>>& ans) {

    int n = nums.size();

    if (ds.size() == n) { // base case
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < n; i++) {

        if (!freq[i]) { // if not used

            ds.push_back(nums[i]); // pick element
            freq[i] = 1;          // mark

            recurPermute(nums, ds, freq, ans);

            freq[i] = 0;          // unmark (backtrack)
            ds.pop_back();        // remove last element
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {

    vector<vector<int>> ans;
    vector<int> ds;
    vector<int> freq(nums.size(), 0);

    recurPermute(nums, ds, freq, ans);
    return ans;
}

// Approach -2 : swapping

// Time Complexity: O(N! X N)
// Space Complexity: O(1)

class Solution {

    private:

        void recurPermute(int index, vector < int > & nums, vector < vector < int >> & ans) {

            if (index == nums.size()) { // base case
            
                ans.push_back(nums);
                return;
            }
            // Note : if i want unique permutations:
            // unordered_set<int>used;

            for (int i = index; i < nums.size(); i++) {

                // if(used.count(nums[i])) continue;
                // used.insert(nums[i]);
                
                swap(nums[index], nums[i]); // swap
                recurPermute(index + 1, nums, ans); // next pointer move call
                swap(nums[index], nums[i]); // reswap after back
            }
        }

    public:

        vector < vector < int >> permute(vector < int > & nums) {

            vector < vector < int >> ans;

            recurPermute(0, nums, ans);
            return ans;
        }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++) cin >> nums[i];

    // vector<vector<int>> ans = permute(nums);

    // Approach -2
    Solution obj;
    vector < vector < int >> ans = obj.permute(nums);

    cout << "All Permutations:" << endl;
    cout << "[" << endl;
    for (auto &perm : ans) {
        cout << " [ ";
        for (int x : perm) cout << x << " ";
        cout << "]," << endl;
    }
    cout << "]" << endl;

    return 0;
}
