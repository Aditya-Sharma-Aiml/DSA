#include<vector> 
#include<iostream>
#include<unordered_map>
using namespace std;


vector<int> intersectionOfSortedArray(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size();
    int m = arr2.size();
    int i = 0, j = 0;
    vector<int> ans;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            i++;
        }
        else if (arr2[j] < arr1[i]) {
            j++;
        }
        else { // arr1[i] == arr2[j]
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    return ans;
}
// intersection of two unsorted array
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        
        if (nums1.size() > nums2.size()) {
            return intersect(nums2, nums1);
        }

        unordered_map<int,int>count;

        vector<int>result;
        
        for(auto num1 : nums1){
            count[num1]++;
        }
        for(auto num2 : nums2){
            if(count[num2]>0){
                result.push_back(num2);
                count[num2]--;
            }
        }
        return result ; 
    }
int main() {
    int n, m; 
    cin >> n >> m;
    vector<int> arr1, arr2;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        arr1.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int y;
        cin >> y;
        arr2.push_back(y); 
    }

    vector<int> ans = intersectionOfSortedArray(arr1, arr2);
    cout << "Intersection of Sorted arr1 and arr2: ";
    for (auto it : ans) {
        cout << it << " ";
    }
    cout << endl;

    vector<int> result = intersect(arr1, arr2);
    cout << "Intersection of arr1 and arr2(array is not sorted): ";
    for (auto it : result) {
        cout << it << " ";
    }
    cout << endl;


    return 0;
}
