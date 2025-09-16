#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;
// Leaders : every element on the right side of a element should be smaller to have element as a Leader , catch is last one is always a leader element

// Brute force
vector<int>superiorElement(vector<int>&arr){

    int n = arr.size();
    //space: o(n) -> only for returning answer
    vector<int>ans;

    //~o(n^2)
    for(int i = 0 ; i < n ;i++){

        bool leader = true;

        for(int j=i+1 ; j<n ;j++){

            if(arr[j]>arr[i]){
                leader = false;
                break;
            }
        }
        
        if(leader) {
            ans.push_back(arr[i]);
        }
    }
}

//Optimal : back traverse (current element > max(other elemeent on right side) then current element would be a leader)
vector<int>leaders(vector<int>&arr){

    int n = arr.size();
    //space: o(n) -> only for returning answer
    vector<int>ans;
    int maxi = INT_MIN;

    // o(n)
    for(int i = n-1 ; i>=0 ;i--){

        if(arr[i]>maxi){
            ans.push_back(arr[i]);
        }
        maxi = max(maxi , arr[i]);
    }
    // sort(ans.begin(),ans.end()); -> o(nlogn)
    // reverse(ans.begin(),ans.end()); -> o(n)
    return ans;

    
}
int main(){
    int n ;
    cin >> n ;
    vector<int> arr;
    for(int i=0 ;i<n ;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    vector<int>ans = leaders(arr);
    for(auto l : ans){
        cout << l << " ";
    }

    
    
}