#include<bits/stdc++.h>
using namespace std;

// move -> 1-step or 2-step : max number of path to reach n
int stairPath(int n){// uper chadne ke wajay niche utaro to n->0

    // base case : 0th pe 1 tarika wahi se wahi and n-2 ki wjah se -1 pe ja skte ho toh not any path 
    if (n==0) return 1;
    if (n<0) return 0;
    
    // nth pe ya toh n-1(1-step) se aaye hoge ya n-2 (2-step) se 
    return stairPath(n-1) + stairPath(n-2);

}
int main(){

    int n;
    cin >> n;
    int totalPath = stairPath(n);
    cout << totalPath;

}