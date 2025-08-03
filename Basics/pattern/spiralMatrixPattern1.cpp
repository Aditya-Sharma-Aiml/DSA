#include <bits/stdc++.h>
using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) {
    vector<int> ans;

    int top = 0, bottom = n - 1;
    int left = 0, right = m - 1;

    while (top <= bottom && left <= right) {
        // Traverse from Left to Right
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;

        // Traverse from Top to Bottom
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;

        // Traverse from Right to Left
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);
            bottom--;
        }

        // Traverse from Bottom to Top
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);
            left++;
        }
    }

    return ans;
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            cin >> matrix[i][j];

    vector<int> result = spiralPathMatrix(matrix, n, m);

    for (int x : result)
        cout << x << " ";
    cout << endl;

    return 0;
}
