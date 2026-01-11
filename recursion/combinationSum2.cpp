#include<bits/stdc++.h>
using namespace std;

// Complexity Analysis

// Time Complexity: O(2n * k), For each of the 2n subsequences, storing takes O(k) time where k is the average length of each combination.

// Space Complexity: O(k * x), To store all x valid combinations, each of average length k.

// xxxxxxxxxxxx  Function to find all combinations(unique) of numbers that sum up to the target xxxxxxxxxxxxx

void findCombination(int idx, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& ds) {
    // Base case: If the target becomes 0, we found a valid combination
    if (target == 0) {
        ans.push_back(ds);  // Add the current combination to the result
        return;
    }

    // Loop through the elements starting from index 'idx'
    for (int i = idx; i < arr.size(); i++) {
        // Skip duplicates to avoid repeating combinations
        if (i > idx && arr[i] == arr[i - 1]) continue;

        // If the current element is greater than the remaining target, break the loop
        if (arr[i] > target) break;

        // Include the current element in the combination
        ds.push_back(arr[i]);

        // Recur with the updated target and next index (i + 1 to avoid repetition)
        findCombination(i + 1, target - arr[i], arr, ans, ds);

        // Backtrack by removing the last added element
        ds.pop_back();
    }
}

// Function to calculate all unique combinations that sum up to the target
vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

    sort(candidates.begin(), candidates.end());  // Sort the candidates to handle duplicates

    vector<vector<int>> ans;  
    vector<int> ds;  // To store the current combination

    findCombination(0, target, candidates, ans, ds);  // Call the helper function

    return ans;  // Return all valid combinations
}

int main() {
    // Example input
    vector<int> v{10, 1, 2, 7, 6, 1, 5};

    // Get all combinations that sum up to 8
    vector<vector<int>> comb = combinationSum2(v, 8);

    // Output the combinations
    cout << "[ ";
    for (int i = 0; i < comb.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < comb[i].size(); j++) {
            cout << comb[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";

    return 0;
}
