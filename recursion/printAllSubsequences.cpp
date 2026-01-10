#include<bits/stdc++.h>
using namespace std;

// Complexity Analysis

// Time Complexity: O(n * 2^n), for each subsequence, we construct and print the entire subsequence.

// Space Complexity: O(n * 2^n), space used to store all possible subsequences.

void allSubsequence(int idx, vector<int>&arr,vector<int>&ds,int n,vector<vector<int>>&ans){

    
    if(idx==n) {
        ans.push_back(ds);
        return ;
    }
    //take
    ds.push_back(arr[idx]);
    allSubsequence(idx+1,arr,ds,n,ans);
    
    // Backtrack: remove last before returning to previous call
    ds.pop_back();
    
    //not take
    allSubsequence(idx+1,arr,ds,n,ans);


}
int main(){
    int n;
    cin >> n;
    vector<int>arr(n);
    vector<vector<int>>ans;
    for (int  i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    vector<int>ds;
    allSubsequence(0,arr,ds,n,ans);
    for (vector<int> seq : ans){
        cout << "{";
        for(int s  : seq){
            cout << s << ", ";
        }
        cout << "}" << endl;
        
    }
    
}