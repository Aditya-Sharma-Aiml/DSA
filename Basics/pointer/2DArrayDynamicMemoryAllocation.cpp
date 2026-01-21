#include<bits/stdc++.h>
using namespace std;

int main(){

    int rows, cols;
    cin >> rows >> cols;

    // CREATING 2D ARRAY
    int** matrix = new int* [rows]; // creating first n rows of int* type box
    // creating col no. of box int array : resultant -> rows * cols
    for(int i=0; i<rows; i++){

        matrix[i] = new int [cols];
    }

    //TAKING INPUT
    for(int i=0; i<rows ; i++){
        
        for(int j=0; j<cols ; j++){

            cin >> matrix[i][j];
        }
    }
    // SHOW OUTPUT
    for(int i=0; i<rows ; i++){

        for(int j=0; j<cols ; j++){

            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    //RELEASING HEAP MEMEORY
    for(int i=0; i<rows; i++){
        delete matrix[i];
    }
    delete [] matrix;
    
}