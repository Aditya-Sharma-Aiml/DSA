#include<bits/stdc++.h>
using namespace std;
// map-> have unique keys and always in sorted order (map<key_dataType,value_dataType>)
int intHashArray(long long int arr[], long long int n, long long int num){
    // prestore
    unordered_map<long long int ,long long int>mpp;

    for(long long int i=0 ;i<n;i++){
        mpp[arr[i]]++;
        
    }
    // for(auto it : mpp){
    //     cout << it.first << " -> " << it.second << endl;
    // }

    return mpp[num];
}


int main(){
    long long int n;
    cin >> n;
    long long int arr[n]={0};
    for(int i = 0; i < n; i++) {
         cin >> arr[i]; 
    }
    
    int q;
    cin >> q;
    // fetch
    while(q--){
        long long int num ;
        cin >> num;
        int count = intHashArray(arr, n, num);
        cout<< count<<endl;

    }
    
        
    

}