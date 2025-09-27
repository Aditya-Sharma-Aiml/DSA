#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//BruteForce:  using Extra Space
// Time Complexity: O(n+m) + O(n+m)
// Space Complexity: O(n+m) 

void mergeTwoSortedArrayWithExtraSpace(long long arr1[], long long arr2[], int n, int m) {

    //Declare a 3rd array and 2 pointers:
    long long arr3[n + m];
    int left = 0;
    int right = 0;

    int index = 0;

    //Insert the elements from the 2 arraysinto the 3rd array using left and rightpointers:

    while (left < n && right < m) {

        if (arr1[left] <= arr2[right]) {

            arr3[index] = arr1[left];
            left++, index++;
        }
        else {

            arr3[index] = arr2[right];
            right++, index++;
        }
    }

    // If right pointer reaches the end:
    while (left < n) {

        arr3[index++] = arr1[left++];
    }

    // If left pointer reaches the end:
    while (right < m) {

        arr3[index++] = arr2[right++];
    }

    // Fill back the elements from arr3[]
    // to arr1[] and arr2[]:
    for (int i = 0; i < n + m; i++) {

        if (i < n) arr1[i] = arr3[i];

        else arr2[i - n] = arr3[i];
    }
}

// optimal : merge without using extra space:

//optimal 1: left -> maximum of arr1 and right -> minimum of arr2 and after this swapping finally sort each array individually
//Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm), space: o(1)

void mergeTwoSortedArrayOptimal1(long long arr1[], long long arr2[], int n, int m) {

    int left = n-1;
    int right = 0;

    while(left>=0 && right<m){

        if(arr1[left] > arr2[right]){

            swap(arr1[left], arr2[right]);
            left--;
            right++;
        }
        else break;
    }
    // Sort arr1[] and arr2[] individually:
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);
}


//optimal 2: Shell sort concept (gap method)
// Time Complexity: O((n+m)*log(n+m)) , space: o(1)

void swapIfGreater(long long arr1[], long long arr2[], int index1, int index2) {

    if (arr1[index1] > arr2[index2]) {
        swap(arr1[index1], arr2[index2]);
    }
}

void mergeTwoSortedArrayOptimal2(long long arr1[], long long arr2[], int n, int m) {
    // len of the imaginary single array:
    int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2); // ceil(len)

    while (gap > 0) {

        // Place 2 pointers:
        int left = 0;
        int right = left + gap;

        while (right < len) {

            // case 1: left in arr1[] and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(arr1, arr2, left, right - n);
            }

            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(arr2, arr2, left - n, right - n);
            }

            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(arr1, arr1, left, right);
            }

            left++, right++;
        }

        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }
}


int main(){
    int n , m;
    cin >> n >> m;

    long long arr1[n] = {0};
    long long arr2[m] = {0};

    for(int i=0 ; i<n ; i++){
        cin>> arr1[i];
    }
    for(int i=0 ; i<m ; i++){
        cin>> arr2[i];
    }
    mergeTwoSortedArrayOptimal2(arr1,arr2,n,m);
    cout<< "Merged Two Sorted Array :" << endl;
    cout << "arr1[] = ";
    for(int i=0 ; i<n ; i++){
        cout<< arr1[i] <<" ";
    }
    cout << endl;
    cout << "arr2[] = ";
    for(int i=0 ; i<m ; i++){
        cout << arr2[i]<<" ";
    }


}