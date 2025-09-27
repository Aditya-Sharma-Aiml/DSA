#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

// BruteForce 
int bruteForceCountSubArrayWithXorK(vector<int>arr,int k){

    int count = 0;
    int n = arr.size();

    for(int i=0 ; i<n ; i++){

        for(int j=i ; j<n ; j++){

            int XOR = 0;

            for(int l=i ; l<=j ; l++){
                
                XOR ^= arr[l];
                if (XOR==k) count++;
            }

        }
    }
    return count;

}
int betterCountSubArrayWithXorK(vector<int>arr,int k){

    int count = 0;
    int n = arr.size();

    for(int i=0 ; i<n ; i++){

        int XOR = 0;

        for(int j=i ; j<n ; j++){

            XOR ^= arr[j];
            if (XOR==k) count++;           

        }
    }
    return count;

}
int countSubArrayWithXorK(vector<int>&arr ,int k){

    int n = arr.size();
    unordered_map<int,int>mpp;

    int count = 0;
    int xr = 0;
    mpp[xr]++;

    for(int i=0 ; i<n ;i++){
        
        // front Xor 
        xr = xr ^ arr[i];

        //looking for k 
        int x = xr ^ k;

        // count ko jitni baar xr aaya hai badhana hai
        count += mpp[x];
        mpp[xr]++;

    }
    return count;


}
int main(){
    int n ,k;
    cin >> n >> k;
    vector<int>arr(n,0);
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];
    }
    cout << countSubArrayWithXorK(arr,k);

}
