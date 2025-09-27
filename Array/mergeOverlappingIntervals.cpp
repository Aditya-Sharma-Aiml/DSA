#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Brute Force: 
// Time Complexity: O(N*logN) + O(2*N)
// Space Complexity: O(N)

vector<vector<int>>bruteForceMergeOverlappingIntervals(vector<vector<int>>&arr){

    int n = arr.size();
    vector<vector<int>>ans;

    sort(arr.begin() , arr.end());

    for(int i = 0 ; i<n ; i++){
        // select an intrval
        int start = arr[i][0];
        int end = arr[i][1];
         //Skip all the merged intervals(already contain):
        if ( !ans.empty() && end <= ans.back()[1]){
            continue;
        }

        // check for others and merge
        for(int j = i+1 ; j<n ; j++){

            if (arr[j][0] <= end){

                end = max(end,arr[j][1]);
            }
            else{
                break;
            }
        }
        ans.push_back({start,end});
    }
    return ans;

}

//Optimal:
// Time Complexity: O(N*logN) + O(N)
// Space Complexity: O(N)

vector<vector<int>>mergeOverlappingIntervals(vector<vector<int>>&arr){
    
    int n = arr.size();
    vector<vector<int>>ans;

    //sort
    sort(arr.begin(), arr.end());

    for(int i=0 ; i<n ; i++){

        // if the current interval does not
        // lie in the last interval:

        if ( ans.empty() || arr[i][0] > ans.back()[1] ){
            //take new interval
            ans.push_back(arr[i]);

        }

        // if the current interval
        // lies in the last interval:
        else{
            //merge intervals
            ans.back()[1] = max( ans.back()[1] , arr[i][1]);

        }
    }
    return ans;
}

int main(){

    // // //user input : 
    // int n;
    // int m;
    // cin >>n >> m;
    // vector<vector<int>>arr(n,vector<int>(m));

    // for(int i = 0 ; i<n ; i++){

    //     for(int j = 0 ; j<m ; j++){

    //         cin >> arr[i][j];
    //     }
    // }

    // vector<vector<int>>arr;

    // for(int i=0 ; i<n ;i++){

    //     vector<int>row;

    //     for(int j = 0 ; j<m ; j++){

    //         int x;
    //         cin >> x;
    //         row.push_back(x);

    //     }
    //     arr.push_back(row);
    // }

    vector<vector<int>> arr = {{1, 3}, {2, 6}, {8, 9},{9,11}, {8,10}, {2,4}, {15,18}, {15, 17}};
    // {1,3} -> 1,2,3
    vector<vector<int>> ans = mergeOverlappingIntervals(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
}