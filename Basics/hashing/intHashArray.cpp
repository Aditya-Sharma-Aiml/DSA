#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 10;
int hashArr[N]; // large enough for any element

int hashArray(int arr[], int size, int num) {
    //prestoring 
    for(int i = 0; i < size; i++) {
        hashArr[arr[i]]++;
        
    }
    return hashArr[num];  
}

int main() {
    int size;
    cin >> size;

    int arr[size];
    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int q;
    cin >> q;
    while(q--) {
        //fetch
        int num;
        cin >> num;
        int count = hashArray(arr, size, num); 
        cout << count << endl;
    }

    return 0;
}
