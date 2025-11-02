#include<iostream>
#include<vector>
using namespace std;

// NOTE :
// 1-> each row is sorted but column is not 
// 2-> last element of previous row is less than next first element of next row => entire matrix is sorted according to row

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

// Better : time=> O(N)+ O(LogM) = O(N)
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
        if(matrix[i][0] <= target && target <= matrix[i][m-1]){
            return binarySearch(matrix[i] , target);
        }
    }
    return false;
    
}

// Optimal : time => O(log(N * M))
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0;
        int high = m * n - 1;

        //imagine 2D as 1D
        while(low <= high){

            int mid = low + (high - low)/2;

            int row = mid / m;
            int col = mid % m;

            if(matrix[row][col]==target) return true;
            else if (target > matrix[row][col]) low = mid + 1;
            else high = mid - 1;
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
    cout <<"Is Element exist : "<<searchMatrix(matrix, target) << endl;
}
