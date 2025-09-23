#include<vector>
#include<iostream>
#include<map>
#include<unordered_map>
#include<climits>


using namespace std;

// majorityElement that appears > [n/3] times -> at max 2 element

//Brute force (n^2)
vector<int> majorityElement(vector<int>&arr){

    vector<int>ans;
    int n = arr.size();

    for(int i = 0 ; i < n ; i++ ){

        int count = 0;
        if(ans.size()==0 || arr[i] != ans[0]){

            for(int j = 0 ; j<n ; j++){
                if (arr[i]==arr[j]) count++;
            }
            // least occurrence of the majority element:
            int mini = (int)(n/3)+1;

            if(count>=mini) ans.push_back(arr[i]);
        }
        if(ans.size()==2) return ans;
       
    }
    

}


// hashing :O(N){ OR N log N } and space -> O(N)
vector<int> majorityElementHashing(vector<int>&arr){    
    
    int n = arr.size();
    // N
    unordered_map<int , int>mpp;
    vector<int>ans;

    // N log N
    //map<int , int>mpp;

    // least occurrence of the majority element:
    int mini = (int)(n/3)+1;

    for(int i=0 ; i<n ; i++){

        mpp[arr[i]]++;
        //checking if arr[i] is the majority element:
        if(mpp[arr[i]]==mini)  ans.push_back(arr[i]);

        if(ans.size()==2) break;
            
    }
    return ans;
    


}

// Moore's Voting Algorithm : O(N) +  O(N){extra for check}
vector<int> majorityElementMooreAlgo(vector<int>&arr){

    int n = arr.size();
    int count1 = 0;
    int count2 = 0;
    int element1 = INT_MIN;
    int element2 = INT_MIN;
    
    // applying the Extended Boyer Moore's Voting Algorithm:
    for(int i=0 ; i<n ; i++){

        if(count1==0 && arr[i] != element2){
            element1 = arr[i];
            count1 = 1;
        }
        else if(count2==0 && arr[i] != element1){
            element2 = arr[i];
            count2 = 1;
        }

        else if (arr[i]==element1){
            count1++;
        }
        else if (arr[i]==element2){
            count2++;
        }

        else{
            count1--;
            count2--;
        }
    }

    // explicitely check element1 and element2 are possible ans or not
    vector<int>ans;
    int cnt1 = 0 , cnt2 = 0;

    for(int i=0 ; i<n ;i++ ){

        if (arr[i]==element1) cnt1++;
        if (arr[i]==element2) cnt2++;    

    }  

    int mini = (int)(n/3)+1;

    if (cnt1>=mini) ans.push_back(element1);
    if (cnt2>=mini) ans.push_back(element2);

    return ans;
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
    vector<int>ls1 = majorityElement(arr);
    vector<int>ls2 = majorityElementHashing(arr);
    vector<int>ls3 = majorityElementMooreAlgo(arr);
    for(auto ele : ls1){
        cout<< ele << " ";
    }
    cout << endl;
    for(auto ele : ls2){
        cout<< ele << " ";
    }
    cout << endl;
    for(auto ele : ls3){
        cout<< ele << " ";
    }
    cout << endl;
    
}