#include<bits/stdc++.h>
using namespace std;
// time : O(lon(n))

// Lower bound => smallest index such that arr[index] >= x where x is any number But if no such arr[index] >= x then return size of array


int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int lower_bound= n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {

            lower_bound = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return  lower_bound;

}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = 5, x = 9;
    int ind = lowerBound(arr, n, x);
    cout << "The lower bound is the index: " << ind << "\n";

    //direct stl

    int lb = lower_bound(arr.begin() ,  arr.end() , x) - arr.begin();
    cout << "Lower Bound: " << lb;
    return 0; 
}
