#include<bits/stdc++.h>
using namespace std;

// Brute Force => Time Complexity: O(N*N) , Space Complexity: O(N*N) 
vector<vector<int>> bruteForceRotate(vector < vector < int >> & matrix) {

    int n = matrix.size();
    vector<vector<int>>rotated(n, vector<int>(n,0));

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            rotated[j][n-i-1] = matrix[i][j];
        }
    }
    return rotated;
}

// Optimal => Time Complexity: O(N*N) + O(N*N) , space : O(1)
void rotate(vector<vector<int>>&matrix){

    int n = matrix.size();
    
    //transposing the matrix
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < i; j++) {

            swap(matrix[i][j], matrix[j][i]);
        }
    }

    //reverse each row
    for(int i=0 ; i<n ;i++){
        // matrix[i] is row
        reverse(matrix[i].begin(),matrix[i].end());
    }

}
int main() {
    vector < vector < int >> arr;
    arr =  {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    rotate(arr);

    cout << "Rotated Image" << endl;
    for (int i = 0; i < arr.size(); i++) {

        for (int j = 0; j < arr[0].size(); j++) {

            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }


}