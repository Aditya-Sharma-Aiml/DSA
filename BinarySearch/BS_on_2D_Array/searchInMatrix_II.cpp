#include<bits/stdc++.h>
using namespace std;

// NOTE: 
//1-> Integers in each row are sorted in ascending from left to right.
// 2-> Integers in each column are sorted in ascending from top to bottom.

// BruteForce : O(M*N)
bool linearSearch(vector<vector<int>>&matrix , int target){
    
    int n = matrix.size();
    int m = matrix[0].size();
    
    for (int i = 0; i < n; i++)
    {
    for (int j = 0; j < m; j++)
        {
            if(matrix[i][j]==target) return true;
        }
        
    }
    return false;
    
}

// Better : time=> O(N * log M)
bool binarySearch(vector<int>arr , int target){
    int n = arr.size();
    int low = 0, high = n-1;

    while(low <= high){
        
        int mid = low +(high - low )/2;
        
        if(arr[mid]==target) return true;
        else if (target > arr[mid]) low = mid + 1;
        else high = mid - 1;
    }
    return false;
}
bool searchInMatrix_better(vector<vector<int>>&matrix , int target){
    int n = matrix.size();
    int m = matrix[0].size();

    for (int i = 0; i < n; i++)
    {   
        // target exist in a particular rowArray
        
        // you can't check like this because matrix is not  sorted as continuous row order => so you have to BS on each row
        
        // if(matrix[i][0] <= target && target <= matrix[i][m-1]){
        //     return binarySearch(matrix[i] , target);
        // }

        // according to NOTE => BS on each row
        bool flag =  binarySearch(matrix[i], target);
        if (flag) return true;
    }
    return false;
    
}

// Optimal: time => O(N + M)
bool searchElement(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();

    // start from top right corner (you can also start from bottom left corner)
    int row = 0, col = m - 1;

    //traverse the matrix from (0, m-1):
    while (row < n && col >= 0) {

        if (matrix[row][col] == target) return true;

        else if (matrix[row][col] < target) row++;

        else col--;
    }
    return false;
}
int main(){
    int n, m;
    int target;
    cin >> n >> m;
    cin >> target;

    vector<vector<int>> matrix(n, vector<int>(m, 0)); // initialized with 0
    for(int i=0 ;i<n ; i++){   
        for(int j=0 ; j<m ; j++){
            cin >> matrix[i][j];
        }  
    }
    cout <<"Is Element exist : "<<linearSearch(matrix, target) << endl;
    cout <<"Is Element exist : "<<searchInMatrix_better(matrix, target) << endl;
    cout <<"Is Element exist : "<<searchElement(matrix, target) << endl;
}