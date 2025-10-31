
#include <bits/stdc++.h>
using namespace std;

int floorSqrt_BruteForce(int n) {
    int ans = 0;
    //linear search on the answer space:  O(root(N))
    for (long long i = 1; i * i<= n; i++) {

        long long val = i * i;

        if (val <= n * 1ll) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}
//Optimal : O(logN)

int floorSqrt(int n) {
    
    int low = 1 , high = n;
    while(low <= high ){

        // handle overflow
        long long mid = low + (high - low)/2;
        long long val = mid * mid ;

        if(val <= (long long)(n)){
            // ans possible : eliminate left
            low = mid + 1;

        }
        else {
            // ans NOT possible : eliminate right
            high = mid - 1;
        }

    }
    return high ;

}
int main()
{
    int n = 28;
    // int ans = sqrt(n); // STL
    int ans = floorSqrt(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}