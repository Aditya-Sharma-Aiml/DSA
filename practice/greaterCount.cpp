#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> arr(n);
    
    int count = 0;
    int maxi = INT_MIN;

    for(int i=0; i<n ; i++){
        
        cin >> arr[i];
        
        if(i==0){
            maxi = arr[i];
            count++;
            continue;
        }
        
        else{
            
           if(arr[i] > maxi){
               count++;
               maxi = arr[i];
           } 
        }
    }
    
    cout << count;
    

    return 0;
}