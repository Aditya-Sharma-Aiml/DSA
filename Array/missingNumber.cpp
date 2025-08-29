#include<iostream>
#include<vector>
using namespace std;
// brute force
int missingNum(vector<int>  &arr , int n){
    for(int i = 1 ; i < n ;i++){
        int flag =0 ;
        for(int j = 0 ; j < n-1 ; j++){
            if(arr[j]==i){
                flag = 1;
            }
        }
        cout << "missing num is (brute force) : ";
        if(flag==0) cout << i << endl;
    }

}
// diff of sum
int missingNumBetter(vector<int>  &arr , int n){
    long s1 = n*(n+1)/2;

    int s2=0 ;
    for(int i =0 ; i<n-1 ;i++){

        s2+=arr[i];
    }
    cout << "missing num is (diff of sum): " << s1-s2;   
}
// xorall ^ xornum
int missingNumBest(vector<int>  &arr , int n){
    int xorall=0;
    int xornum = 0;

    if(n%4==0) xorall = n;
    else if(n%4==1) xorall = 1;
    else if (n%4==3) xorall = n+1 ;
    else xorall=0;

    for(int i = 0 ;i<n-1 ;i++){
        xornum^=arr[i];

    }

    cout << "missing num is (xor): " << (xorall ^ xornum);  
}
int main(){
    int n;
    cin >> n;
    vector<int> arr;
    for(int i = 0 ; i< n-1 ; i++){
        int x;
        cin >>x ;
        arr.push_back(x);

    }
    // missingNum(arr , n);
    // missingNumBetter(arr,n);
    missingNumBest(arr,n);


}