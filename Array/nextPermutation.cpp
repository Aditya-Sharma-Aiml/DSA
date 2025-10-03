#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(3N)
// Space Complexity: O(1)

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int index = -1;

        // Step 1: find break-point
        for (int i = n - 2; i >= 0; i--) {

            if (nums[i] < nums[i + 1]) {

                index = i;// i is break point
                break;
            }
        }

        // If no break-point found, reverse whole array
        if (index == -1) {

            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: find next greater element on right
        for (int i = n - 1; i > index; i--) {

            if (nums[i] > nums[index]) {

                swap(nums[i], nums[index]);
                break;
            }
        }

        // Step 3: reverse the suffix
        reverse(nums.begin() + index + 1, nums.end());
    }
};

int main() {
    Solution sol;

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    sol.nextPermutation(nums);

    cout << "Next permutation: ";
    for (int x : nums) cout << x << " ";
    cout << endl;

    return 0;
}
