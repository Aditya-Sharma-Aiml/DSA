#include<bits/stdc++.h>
using namespace std;

int linearSearch(int *arr, int size, int key){

    if(size == 0) return 0;

    if(arr[0] == key ) return 1;
    else
        return linearSearch(arr+1, size - 1, key);
    
}

int main(){

    int n;
    cin >> n;

    int *arr = new int[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    int key;
    cin >> key;
    cout << linearSearch(arr, n, key);

}