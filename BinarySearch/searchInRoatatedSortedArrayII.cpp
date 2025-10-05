#include <bits/stdc++.h>
using namespace std;

// Optimal => Time Complexity: O(logN) for the best and average case. O(N/2) for the worst case

// Array : contain Duplicat Elements
bool searchInARotatedSortedArrayII(vector<int>&arr, int target) {

    int n = arr.size(); 
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == target) return true;

        //Edge case: handle duplicates
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            // shrink search space untill feagure out which half is sorted
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= target && target <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= target && target <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    int target = 3;
    bool ans = searchInARotatedSortedArrayII(arr, target);
    if (!ans)
        cout << "Target is not present.\n";
    else
        cout << "Target is present in the array.\n";
    return 0;
}
