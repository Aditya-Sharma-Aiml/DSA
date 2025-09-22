#include<bits/stdc++.h>
using namespace std;
/*
Pascal Triangle : use formula : nCr -> (r-1)C(c-1)
                1)given row and column and tell the element at that place  
                2)print any Nth row of the Pascal Triangle 
                3)print entire Triangle

                note : (n / 1)*((n-1) / 2)*.....*((n-r+1) / r).
                n -> row-1
                r -> column-1
*/ 
int nCr(int row , int col){

    int ans = 1;

    for(int c = 0 ; c < col ;c++ ){

        ans *= (row - c);
        ans /= c;

    }
    return ans;
} 
// case 1 : given row and column and tell the element at that place  => O(c)

int elementOfPascalTriangle(int r, int c) {

    int element = nCr(r - 1, c - 1);
    cout <<  element;
}
//case 2 : print any Nth row of the Pascal Triangle  => Time Complexity: O(n*r)

void nthRowOfPascalTriangle(int n) {
    
    for (int c = 1; c <= n; c++) {
        cout << nCr(n - 1, c - 1) << " ";
    }
    cout << "\n";
}
//case 3 : print entire Triangle => Time Complexity: O(n^2)

vector<int> generateRow(int row) {

    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {

        ans.push_back(generateRow(row));

    }
    return ans;
}



int main(){
    int n , row , col;

    cin >> n ;
    cin >> row >> col;

    //case: 1 
    elementOfPascalTriangle(row,col);
    cout << endl;

    //case: 2
    nthRowOfPascalTriangle(row);
    cout << endl;

    //case: 3
    vector<vector<int>> ans = pascalTriangle(n);

    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    return 0;
}