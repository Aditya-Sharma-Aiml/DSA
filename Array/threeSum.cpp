
#include <bits/stdc++.h>
using namespace std;

// Brute Force : 

// Time Complexity: O(N3 * log(no. of unique triplets)), where N = size of the array.
// Space Complexity: O(2 * no. of the unique triplets)



vector<vector<int>> bruteForceTriplet(int n, vector<int> &arr) {
    set<vector<int>> st;

    // check all possible triplets:
    for (int i = 0; i < n; i++) {

        for (int j = i + 1; j < n; j++) {

            for (int k = j + 1; k < n; k++) {

                if (arr[i] + arr[j] + arr[k] == 0) {

                    vector<int> temp = {arr[i], arr[j], arr[k]};

                    sort(temp.begin(), temp.end());

                    st.insert(temp);
                }
            }
        }
    }

    //store the set elements in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



// Better : hashing

// Time Complexity: O(N2 * log(no. of unique triplets)), where N = size of the array.
// Space Complexity: O(2 * no. of the unique triplets) + O(N)


vector<vector<int>> BetterApproachTriplet(int n, vector<int> &arr) {
    
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {

        set<int> hashset;

        for (int j = i + 1; j < n; j++) {

            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {

                vector<int> temp = {arr[i], arr[j], third};

                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}



// Optimal : Two Pointer Approach

// Time Complexity: O(NlogN)+O(N2), where N = size of the array.
// Space Complexity: O(no. of Triplets)


vector<vector<int>> triplet(int n, vector<int> &arr) {

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());

    for (int i = 0; i < n; i++) {
        //remove duplicates:
        if (i != 0 && arr[i] == arr[i - 1]) continue;

        //moving 2 pointers:
        int j = i + 1;
        int k = n - 1;

        while (j < k) {

            int sum = arr[i] + arr[j] + arr[k];

            if (sum < 0) {
                j++;
            }
            else if (sum > 0) {
                k--;
            }
            else {

                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);

                j++;
                k--;

                //skip the duplicates:
                while (j < k && arr[j] == arr[j - 1]) j++;
                while (j < k && arr[k] == arr[k + 1]) k--;
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    int n = arr.size();
    vector<vector<int>> ans = triplet(n, arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}