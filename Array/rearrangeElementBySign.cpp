#include<iostream>
#include<vector>
using namespace std;

// problem : rearrange the the altrenate pos and neg

// case 1 : Equal number of positive and negatives

// case 1: brute force => n + n/2 & space-> n
vector<int> bruteForceRearrangebySign(vector<int>A){
    
    vector<int> pos;
    vector<int> neg;
    int n = A.size();

    for(int i=0;i<n;i++){
        
        if(A[i]>0) pos.push_back(A[i]);
        else neg.push_back(A[i]);
    }
  
    // Positives on even indices, negatives on odd.
    for(int i=0;i<n/2;i++){
        
        A[2*i] = pos[i];
        A[2*i+1] = neg[i];
    }
    return A;
    
}
// case 1: optimal => n & space-> n
vector<int> optimalRearrangebySign(vector<int>A){
        
    int n = A.size();
    vector<int> ans(n,0); 
    // positive elements start from 0 and negative from 1.
    int posIndex = 0, negIndex = 1;

    for(int i = 0;i<n;i++){
        
        if(A[i]<0){
            ans[negIndex] = A[i];
            negIndex+=2;
        }
        
        else{
            ans[posIndex] = A[i];
            posIndex+=2;
        }
    }
    
    return ans;
        
}

// case 2: number of +ves and -ves are not equal (be have to back on Brute force for this )
vector<int>RearrangebySign(vector<int>&arr){

    vector<int> pos ,neg;
    int n = arr.size();

    for(int i=0;i<n;i++){

        if(arr[i]>0) pos.push_back(arr[i]);

        else neg.push_back(arr[i]);
    }

    int pLength = pos.size();
    int nLength = neg.size();

    // If positives are lesser than the negatives.
    if(pLength < nLength){

        // First, fill array alternatively till the point 
        // where positives and negatives ar equal in number.

        for(int i=0 ; i<pLength ; i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = pLength *2;

         // Fill the remaining negatives at the end of the array.
        for(int i=pLength ; i<nLength ; i++){
            arr[index] = neg[i];
            index++;
        }
        
    }
    else{ // If negatives are lesser than the positives.
        
        // First, fill array alternatively till the point 
        // where positives and negatives ar equal in number.

        for(int i=0 ; i<nLength ; i++){
            arr[2*i] = pos[i];
            arr[2*i+1] = neg[i];
        }

        int index = nLength *2;

        // Fill the remaining positives at the end of the array.
        for(int i=nLength ; i<pLength ; i++){
            arr[index] = pos[i];
            index++;
        }
    }

    return arr;


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
    RearrangebySign(arr);
    for(auto it : arr){
        cout << it << " ";
    }
}
