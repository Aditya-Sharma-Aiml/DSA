#include <bits/stdc++.h>
using namespace std;

// varient 1 => exist or not

string twoSumVarient1(int n, vector<int> &arr, int target) {

    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {

        int num = arr[i];
        int moreNeeded = target - num;

        if (mpp.find(moreNeeded) != mpp.end()) {
            return "YES";
        }
        mpp[num] = i;
    }
    return "NO";
}
// varient 2 : return indices
vector<int> twoSumVarient2(int n, vector<int> &arr, int target) {

    unordered_map<int, int> mpp;

    for (int i = 0; i < n; i++) {

        int num = arr[i];
        int moreNeeded = target - num;

        if (mpp.find(moreNeeded) != mpp.end()) {
            return {mpp[moreNeeded], i};
        }

        mpp[num] = i;
    }
    return { -1, -1};
}
// two pointer approach for varient 1
string twoSum(int n, vector<int> &arr, int target) {

    sort(arr.begin(), arr.end()); // imp

    int left = 0, right = n - 1;

    while (left < right) {

        int sum = arr[left] + arr[right];

        if (sum == target) {
            return "YES";
        }

        else if (sum < target) left++;

        else right--;
    }

    return "NO";
}
int main(){
    int n , target;
    cin >> n >> target;
    vector<int> arr;
    for(int i=0 ;i<n ;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    string result = twoSumVarient1(n,arr,target);
    vector<int> resultIndices = twoSumVarient2(n ,arr,target);
    cout << result << endl;
    for(auto index : resultIndices){
        cout << index << " ";
    }
    




}