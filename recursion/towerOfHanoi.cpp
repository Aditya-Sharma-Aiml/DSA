#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int towerOfHanoi(int n, int from, int to, int aux) {
        
        // Base case
        if (n == 1) {
            cout << "move disk "<< n <<" from rod " << from << " to rod " << to << endl;
            return 1;
        }

        int minMove = 0;
        
        // 1st -> "from" se n-1 leke "aux" me daal do "to" ki help se
        minMove += towerOfHanoi(n-1, from, aux, to);
        
        // 2nd -> last nth disk ko "from" se direct "to" me daal do
        cout << "move disk " << n << " from rod " << from<< " rod " << to << endl;
        
        minMove += 1; 
        
        //3rd -> "aux" se n-1 disk ko "to" me daal do "from" ki help se
        minMove += towerOfHanoi(n-1, aux, to, from); 
        
        return minMove;
    }
};

int main(){
    int n ;
    cin >> n;
    Solution sol;

    int minMove = sol.towerOfHanoi(n, 1,2,3);
    cout << "min-move: " << minMove;
}