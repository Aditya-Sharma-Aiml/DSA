#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> generateSpiralMatrix(int n) {
    vector<vector<int>> matrix(n, vector<int>(n, 0));
    
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;
    int num = 1;

    while (top <= bottom && left <= right) {
        // Left to Right
        for (int i = left; i <= right; i++)
            matrix[top][i] = num++;
        top++;

        // Top to Bottom
        for (int i = top; i <= bottom; i++)
            matrix[i][right] = num++;
        right--;

        // Right to Left
        for (int i = right; i >= left; i--)
            matrix[bottom][i] = num++;
        bottom--;

        // Bottom to Top
        for (int i = bottom; i >= top; i--)
            matrix[i][left] = num++;
        left++;
    }

    return matrix;
}

int main() {
    int n;
    cin >> n;

    vector<vector<int>> result = generateSpiralMatrix(n);

    for (const auto& row : result) {
        for (int val : row)
            cout << val << " ";
        cout << endl;
    }

    return 0;
}
