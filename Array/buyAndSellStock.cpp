#include<iostream>
#include<vector>
using namespace std;

// Approach : if you are selling on ith day then you have to buy on the minimum price from 1st to (i-1)th day

int maxProfit(vector<int>& prices) {

    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;

    for(int i = 0 ; i<n ;i++){
        //calculate profit
        int currentProfit = prices[i] - mini;
        maxProfit = max(maxProfit , currentProfit);
        //update minimum
        mini = min(mini , prices[i]);
    }
    return maxProfit;
       
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
    cout << maxProfit(arr);
}
