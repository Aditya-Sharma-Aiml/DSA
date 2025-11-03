#include <bits/stdc++.h>
using namespace std;

// Peak Element : arr[mid-1] < arr[mid] > arr[mid+1]

// O(n)
int findPeakElement_BruteForce(vector<int> &arr) {
    int n = arr.size(); 

    for (int i = 0; i < n; i++) {
        //Checking for the peak:
        if ((i == 0 || arr[i - 1] < arr[i])
                && (i == n - 1 || arr[i] > arr[i + 1])) {
            return i;
        }
    }
    // Dummy return statement
    return -1;
}

//Optimal : Binary Search (logN)
int findPeakElement(vector<int> &arr) {
    int n = arr.size(); 

    // Edge cases:
    // we assume array=> -inifinte on -1 and nth index : -inf{1,2,3,4,5,6,7,8,9}-inf OR -inf{9,8,7,6,5,4,3,2,1}-inf
    // so might be 9 -> peak : at 0 or n-1 pe
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2; // handle overflow

    while (low <= high) {
        int mid = (low + high) / 2;

        //If arr[mid] is the peak:
        if (arr[mid - 1] < arr[mid] && arr[mid] > arr[mid + 1])
            return mid;

        // If peak in the right:
        if (arr[mid] > arr[mid - 1]) low = mid + 1;

        // If peak in the left:

        // Or, arr[mid] is a common point: means it handle array contain multiple peak so we can go left or right 
        else high = mid - 1;
    }
    // Dummy return statement
    return -1;
}
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = findPeakElement(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}