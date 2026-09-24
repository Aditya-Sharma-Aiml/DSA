#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

// Approach: Like Height and Diameter, Here we can use a bottom-up approach to calculate the maximum path sum in a binary tree. We will calculate the maximum path sum that can be obtained from each node and update the overall maximum path sum accordingly. The maximum path sum can be obtained by considering the following cases for each node:
// The maximum path sum that passes through the current node and includes both its left and right children.

//TC: O(N) where N is the number of nodes in the binary tree, as we vi
int maxSumPathDown(Node* root, int &maxSum){
    if(!root) return 0;

    int left = maxSumPathDown(root->left, maxSum);
    int right = maxSumPathDown(root->right, maxSum);

    // Calculate the maximum path sum that passes through the current node
    int currentMax = root->data + left + right;

    // Update the overall maximum path sum if the current path sum is greater
    maxSum = max(maxSum, currentMax);

    // Return the maximum path sum that can be extended to the parent node
    return root->data + max(left, right);
}
int maxPathSum(Node* root){
    int maxSum = INT_MIN; // Initialize the maximum path sum to the smallest possible integer
    maxSumPathDown(root, maxSum); // Start the recursive function to calculate the maximum path sum
    return maxSum; // Return the overall maximum path sum found
}

int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    cout << "Maximum Path Sum: " << maxPathSum(root) << endl;

    return 0;
}