
#include <bits/stdc++.h>
using namespace std;

// O(logN)
// Array : contain Duplicate Element

int findMin(vector<int>& arr) {

    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high) {

        int mid = low + (high - low) / 2;

        //search space is already sorted then arr[low] will always be the minimum in that search space:
        if (arr[low] < arr[high]) {
            ans = min(ans, arr[low]);
            break;
        }
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){ // handle duplicates
                //shrink search space
                ans = min(ans , arr[low]);
                low = low + 1;
                high = high - 1;
                continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            // keep the minimum:
            ans = min(ans, arr[low]);

            // Eliminate left half:
            low = mid + 1;
        }
        else { //if right part is sorted:

            // keep the minimum:
            ans = min(ans, arr[mid]);

            // Eliminate right half:
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {2,2,2,2,2,2,2,2,2,2,2,1,2,2,2,2,2,2,2};
    int ans = findMin(arr);
    cout << "The minimum element is: " << ans << "\n";
    return 0;
}
