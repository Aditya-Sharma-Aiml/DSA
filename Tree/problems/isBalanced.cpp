#include "../buildTree.hpp"
#include "height.cpp"
#include <bits/stdc++.h>
using namespace std;

// brute Force tc-> O(N^2)
// Approach: For each node, we calculate the height of its left and right subtrees and check if the difference is more than 1. If it is, the tree is not balanced. We then recursively check the left and right subtrees for balance.
bool checkBalanced(Node* root){

    if (root == nullptr) return true;

    Height h;
    int lh = h.dfsHeight(root->left);
    int rh = h.dfsHeight(root->right);

    if(abs(lh-rh) > 1) return false; // If the difference in heights is more than 1, the tree is not balanced

    bool left = checkBalanced(root->left); // Check if the left subtree is balanced
    bool right = checkBalanced(root->right); // Check if the right subtree is balanced

    if(!left || !right) return false;// If either subtree is not balanced, the tree is not balanced
    return true;
}

//optimal tc -> O(N)
//approach: We can use a bottom-up approach to check if the tree is balanced. We calculate the height of each subtree and check if the difference in heights is more than 1. If it is, we return -1 to indicate that the tree is not balanced. If the subtree is balanced, we return its height.
int height(Node* root){
    
    if(root == NULL) return 0;

    int lh = height(root->left); 
    if(lh == -1) return -1; // If the left subtree is not balanced, propagate the -1 upwards
    
    int rh = height(root->right);
    if(rh == -1) return -1; // If the right subtree is not balanced, propagate the -1 upwards

    if( abs(lh-rh) > 1) return -1; // If the current node is not balanced, return -1

    return max(lh, rh) + 1; // Return the height of the current subtree
}
bool isBalanced(Node* root){
    return height(root) != -1; // If the height function returns -1, it means the tree is not balanced; otherwise, it is balanced.
}

int main(){
    Tree tree;
    Node* root = tree.buildTree(NULL);

    cout << isBalanced(root) << endl;
    cout << checkBalanced(root) << endl;
}