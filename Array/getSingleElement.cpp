#include <bits/stdc++.h>
using namespace std;

// hashing 
int getSingleElementHashing(vector<int> &arr) {

    int n = arr.size();

    map<int, int> mpp;
    for (int i = 0; i < n; i++) {
        mpp[arr[i]]++;
    }

    //Find the single element and return the answer:
    for(auto it : mpp){
        if(it.second == 1){
            return it.first;
        }
    }
    return -1;
}
int getSingleElementXOR(vector<int> &arr) {
    
    int n = arr.size();
    int xorr = 0;
    for (int i = 0; i < n; i++) {
        xorr = xorr ^ arr[i];
    }
    return xorr;
}
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0 ; i< n ; i++){
        int x;
        cin >>x ;
        arr.push_back(x);

    }
    // int single = getSingleElementXOR(arr);
    int single  = getSingleElementHashing(arr);
    cout << single;
}