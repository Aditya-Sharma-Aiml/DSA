#include<bits/stdc++.h>
using namespace std;

// Time Complexity:O(Nlogn + N)
int findDuplicate_brureForce(vector < int > & arr) {
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n - 1; i++) {
        if (arr[i] == arr[i + 1]) {
        return arr[i];
        }
    }

}

// hashing :Time Complexity: O(N),Space Complexity: O(N), 
int findDuplicate_hashing(vector < int > & arr) {
    int n = arr.size();
    int freq[n + 1] = {0};

    for (int i = 0; i < n; i++) {
        if (freq[arr[i]] == 0) {
            freq[arr[i]] += 1;
        } else {
            return arr[i];
        }
    }
    return 0;
}

// optimal : floyd's cycle detection method (hare and tortoise method)
// time : O(N)
int findDuplicate(vector < int > & nums) {

    int slow = nums[0];
    int fast = nums[0];
    do {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);

    fast = nums[0];
    while (slow != fast) {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}
int main() {
  vector < int > arr;
  arr = {1,3,4,2,2};
  cout << "The duplicate element is " << findDuplicate(arr) << endl;
}