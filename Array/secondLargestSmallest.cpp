#include <bits/stdc++.h> 
using namespace std;

int findSecondLargest(vector<int> &arr,int n)
{
    int largest  = arr[0];
    int slargest  = INT_MIN;
    
    for(int i=0 ; i<n ; i++){

        if(arr[i]>largest){

            slargest = largest;

            largest  = arr[i];
        }
        else if (arr[i]!=largest && arr[i]> slargest){
            slargest  = arr[i];
        }
    }
    if(slargest == INT_MIN) return -1;
    return slargest;
}
int findSecondSmallest(vector<int> &arr , int n)
{
    int smallest  = arr[0];
    int ssmallest  = INT_MAX;

    for(int i=0 ; i<n ; i++){

        if(arr[i]<smallest){

            ssmallest = smallest;

            smallest  = arr[i];
        }
        else if (arr[i]!=smallest && arr[i]< ssmallest){
            ssmallest  = arr[i];
        }
    }
    if(ssmallest == INT_MAX) return -1;
    return ssmallest;
}
vector<int> secondOrderElement(vector<int>&a , int n ){
    int slargest  = findSecondLargest(a,n);
    int ssmallest  = findSecondSmallest(a,n);
    cout << "second Largest : " << slargest << endl;
    cout << "second Smallest : " << ssmallest << endl;

}
int main(){
    int n ; 
    cin >> n;
    vector<int> arr;
    for(int i=0 ; i<n ;i++){
        int x;
        cin >> x;
        arr.push_back(x);
    }
    secondOrderElement(arr,n);

}
