#include<vector> 
#include<iostream>
#include<set>
using namespace std;
// union from two sorted array
vector<int> unionBruteForce( vector<int> &arr1 ,vector<int> &arr2 ){
    set<int>st;
    for(auto it : arr1){
        st.insert(it);
    } 
    for(auto it : arr2){
        st.insert(it);
    } 
    vector<int>Union;
    for(auto it : st){
        Union.push_back(it);
    }
    return Union;
}
vector<int> unionOptimalTwoPointer( vector<int> &arr1 ,vector<int> &arr2 ){

    int n1 = arr1.size();
    int n2 = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> Union;

    while(i<n1 && j<n2){

        if(arr1[i]<=arr2[j]){

            // back() => refer krega union ke last element ko ki kahin wo current arr[i] ke equal to nhi hai na 

            if(Union.size()==0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
        }
        else{

            if(Union.size()==0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;

        }
    }
    while(j<n2){
        
        if(Union.size()==0 || Union.back() != arr2[j]){
                Union.push_back(arr2[j]);
            }
            j++;
    }
    while(i<n1){

        if(Union.size()==0 || Union.back() != arr1[i]){
                Union.push_back(arr1[i]);
            }
            i++;
    }
    return Union;
}
int main(){
    int n;
    int m ; 
    cin >> n >> m;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0 ; i<n ; i++){
        int x;
        cin >> x;
        arr1.push_back(x);

    }
    for(int i=0 ; i<m ; i++){
        int y;
        cin >> y;
        arr2.push_back(y);

    }
    cout << "Brute Force Approach : ";
    vector<int>union_brute_force = unionBruteForce(arr1, arr2);
    for(auto it : union_brute_force){
        cout << it << " ";
    }
    cout << endl;
    cout << "Two pointer Approach : ";
    vector<int>union_optimal = unionBruteForce(arr1, arr2);
    for(auto it : union_optimal){
        cout << it << " ";
    }
    

}