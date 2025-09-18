#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set>
using namespace std;

// Brute Force : Time Complexity=> O(N^2)
bool linearSearch(vector<int>&a, int num) {
    int n = a.size(); 
    for (int i = 0; i < n; i++) {
        if (a[i] == num)
            return true;
    }
    return false;
}
int bruteForceLongestSuccessiveElements(vector<int>&a) {

    int n = a.size();
    int longest = 1;
    //pick a element and search for its
    //consecutive numbers:
    for (int i = 0; i < n; i++) {
        int x = a[i];
        int cnt = 1;
        //search for consecutive numbers
        //using linear search:
        while (linearSearch(a, x + 1) == true) {
            x += 1;
            cnt += 1;
        }

        longest = max(longest, cnt);
    }
    return longest;
}
 
// Better Approach : Time Complexity=> O(NlogN) + O(N) , Space Complexity: O(1)
int betterLongestSuccessiveElements(vector<int>&arr){

    int n = arr.size();
    if (n == 0) return 0;

    sort(arr.begin(),arr.end());
    int lastSmaller = INT_MIN;
    int count = 0;
    int longest = 1;

    for(int i = 0 ; i<n ;i++){
        
        if(arr[i]-1==lastSmaller){

            //a[i] is the next element of the
            //current sequence

            count ++;
            lastSmaller = arr[i];

        }

        // else if(arr[i]==lastSmaller){
        //     // do nothing
        // }

        else if(arr[i]!=lastSmaller){
            //agar lastSmaller is not equal to arr[i] to naye se start kro
            count=1;
            lastSmaller = arr[i];

        }

        longest = max(longest, count);
    }
    return longest;
}

//Optimal Approach : Time => O(3N) , space => O(N)
int longestSuccessiveElements(vector<int>&arr) {
    int n= arr.size();
    if(n==0) return 0;

    int longest = 1;
    unordered_set<int>uset;
    
    for(int i=0 ; i<n ;i++){ // O(N)
        uset.insert(arr[i]);
    }

    for(auto it : uset){ // O(2N) not N^2

        // just previous consecutive number does not exist mean here to start
        if(uset.find(it-1)==uset.end()){

            int count = 1;
            int x = it;

            // go forward in numbers until you didn't found next one 
            while(uset.find(x+1)!=uset.end()){  
                count++;
                x++;
            }

            longest = max(longest , count);

        }
    }

    return longest;


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
    cout << longestSuccessiveElements(arr);
}