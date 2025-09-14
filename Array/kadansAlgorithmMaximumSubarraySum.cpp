#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//Kadan's Algorithm : O(N)

// return SUM
long long maximumSubarraySum(vector<int> &arr){

    int n = arr.size();

    long long maxi = LONG_MIN;
    long long sum = 0;

    for(int i=0 ; i<n ; i++){

        sum += arr[i];
        maxi = max(maxi,sum);
        //if(sum > maxi ) maxi = sum;
        if(sum < 0) sum = 0;
    }
    return max(0LL , maxi);

}

// print SubArray
void printMaximumSubarraySum(vector<int> &arr){

    int n = arr.size();

    long long maxi = LONG_MIN;
    long long sum = 0;

    int start = -1;
    int ansStart = -1;
    int ansEnd = -1;

    for(int i=0 ; i<n ; i++){

        // start making sub array
        if(sum==0) start = i;

        sum += arr[i];

        if(sum > maxi ) {

            maxi = sum;

            ansStart = start;
            ansEnd = i;

        }
        if(sum < 0) sum = 0;
    }
    cout << "Array that have Maximum Sub Array sum : ";
    for(int i = ansStart ; i <= ansEnd ; i++){
        cout << arr[i] << " ";
    }
    

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
    cout <<"sum : "<< maximumSubarraySum(arr) << endl;
    printMaximumSubarraySum(arr);
}