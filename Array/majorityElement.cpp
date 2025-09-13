#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>


using namespace std;

// majorityElement that appears > n/2 times

//Brute force (n^2)
int majorityElement(vector<int>&arr){

    int n = arr.size();
    for(int i = 0 ; i < n ; i++ ){
        int count = 0 ;
        for(int j = 0 ; j < n ; j++){
            if(arr[i]==arr[j]) count ++;
        }
        if(count > (n/2)) return arr[i];
    }
    return -1;

}


// hashing : O(N) +  O(N){ OR N log N } and space -> O(N)
int majorityElementHashing(vector<int>&arr){    
    
    int n = arr.size();
    // N
    unordered_map<int , int>mpp;

    // N log N
    //map<int , int>mpp;

    for(int i=0 ; i<n ; i++){
        mpp[arr[i]]++;
    }
    //N
    for(auto it : mpp){
        if(it.second > (n/2)) return it.first;
        else return -1;
    }


}

// Moore's Voting Algorithm : O(N) +  O(N){extra for check}
int majorityElementMooreAlgo(vector<int>&arr){

    int n = arr.size();
    int count = 0;
    int element;

    for(int i=0 ; i<n ; i++){

        if(count==0){
            element = arr[i];
            count = 1;
        }

        else if (arr[i]==element){
            count++;
        }

        else{
            count--;
        }
    }

    // // if we not sure that majority exist :

    int temp_count = 0;
    for(int i=0 ; i<n ; i++){
        if(arr[i]==element) temp_count++;
    }
    if (temp_count>(n/2)) return element ;
    else return -1;

    // return element;
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
    cout << majorityElementHashing(arr);
    // cout << majorityElementMooreAlgo(arr);
}