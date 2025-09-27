#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);

        int left = 0;
        int right = n - 1;
        int pos = n - 1;

        while (left <= right) {

            int leftSquare = abs(nums[left] * nums[left]);

            int rightSquare = abs(nums[right] * nums[right]);

            if (leftSquare > rightSquare) {

                ans[pos--] = leftSquare;
                left++;

            } else {

                ans[pos--] = rightSquare;
                right--;
            }
        }
        return ans;
    }
};

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);

    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    Solution sol;
    vector<int> result = sol.sortedSquares(nums);

    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}
