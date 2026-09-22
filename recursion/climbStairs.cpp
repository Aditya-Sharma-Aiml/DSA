#include<bits/stdc++.h>
using namespace std;

int climbStairsRecursion(int n) {
    if(n <= 1) return 1;
    return climbStairsRecursion(n-1) + climbStairsRecursion(n-2);
}

int climbStairsDP(int n) {
    if(n <= 1) return 1;
    vector<int> dp(n+1);
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
int climbStairs(int n) {
    if(n <= 2) return n;
    int a = 1, b = 2;
    for(int i=3; i<=n; i++){
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}

int main(){

    int n;
    cin >> n;

    cout << climbStairsRecursion(n) << endl;
    cout << climbStairsDP(n) << endl;
    cout << climbStairs(n) << endl;
}