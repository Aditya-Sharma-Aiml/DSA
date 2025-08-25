#include<iostream>
#include<vector>
#include<set>
using namespace std;
// two pointer approach (optimal)
int removeInplaceDuplicate(int arr[], int n){
    int first = 0;
    for(int second  = 1 ; second < n ; second++){
        if(arr[second]!=arr[first]){
            arr[first+1] = arr[second];
            first++;
        }
    }
    return first+1;
}
// using set (brute force)

int removeInplaceDuplicateBySet(int arr[] , int n){
    set<int>st;
    for(int i = 0 ; i<n ; i++){
        st.insert(arr[i]);
    }
    return st.size();
}
int main(){
    int n;
    cin >> n;
    int arr[n] = {0};
    for(int i=0 ; i<n ; i++){
        cin >> arr[i];

    }
    // number of unique element
    int viaSet = removeInplaceDuplicateBySet(arr,n);
    int viaDoublePointer = removeInplaceDuplicateBySet(arr,n);

    cout<< "no. of unique element (in place) : " << viaSet << " == " << viaDoublePointer;

}
