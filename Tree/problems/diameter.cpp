#include "../buildTree.hpp"
#include "height.cpp"
#include <bits/stdc++.h>
using namespace std;
// Approach: The diameter of a binary tree is the length of the longest path between any two nodes in the tree. This path may or may not pass through the root. 

// There are option cases:
// option 1 : diameter exist in left
// option 2 : diameter exist in right
// option 3 : diameter exist in left and right and pass through root
// ans = max(op1, op2, op3)

class Diameter{
    public:

    // brutefroce approach tc-> O(N^2)

    int diameterBruteForce(Node* root){

        if(!root) return 0;

        int op1 = diameterBruteForce(root->left);
        int op2 = diameterBruteForce(root->right);

        Height h;
        // int op3 = h.dfsHeight(root->left) + h.dfsHeight(root->right) + 1; // +1 for the current node
        int op3 = h.dfsHeight(root->left) + h.dfsHeight(root->right); // edge count not node so we don't add 1 for the current node

        int ans = max(op3, max(op1, op2));

        return ans;
    }

    // optimal 1 : O(N) -> using pair to return both diameter and height in a single traversal

    pair<int, int> diameterHeight(Node* root){

        if(!root ){
            pair<int, int> p= make_pair(0,0);
            return p;

        }

        // op1 : left diameter 
        pair<int, int> left = diameterHeight(root->left); // Calculate the diameter and height of the left subtree
        int op1 = left.first;
 
        //op2 : // right diameter
        pair<int, int> right = diameterHeight(root->right); // Calculate the diameter and height of the right subtree
        int op2 = right.first;

        //op3 : merge left right -> height
        int op3 = left.second + right.second;// edge count not node so we don't add 1 for the current node

        pair<int, int> ans;
        ans.first = max(op1, max(op2, op3));
        ans.second = max(left.second, right.second) + 1;

        return ans;

    }
    int diameterOfBinaryTree(Node* root) {
        return diameterHeight(root).first; 
    }


    // optimal 2 : O(N)
    //Approach : At any node maximun [left height + right height] is the diameter of the tree. So we can calculate the height of the tree and update the diameter at each node.
    int diameter(Node* root) {
        int diameter = 0; // Initialize the diameter to 0
        heightAndUpdateDiameter(root, diameter); // Calculate the height and update the diameter
        return diameter; // Return the final diameter of the tree
    }
    int heightAndUpdateDiameter(Node* node, int& diameter) {
        if (node == nullptr) return 0; // Base case: If the node is NULL, the height is 0

        int leftHeight = heightAndUpdateDiameter(node->left, diameter); // Calculate the height of the left subtree
        int rightHeight = heightAndUpdateDiameter(node->right, diameter); // Calculate the height of the right subtree

        // Update the diameter if the current path through this node is larger
        diameter = max(diameter, leftHeight + rightHeight); // Update the diameter with the maximum value

        return max(leftHeight, rightHeight) + 1; // Return the height of the current node
    }

};


// int main(){
//     Tree tree;
//     Node* root = tree.buildTree(NULL);

//     Diameter d;
//     cout << "Diameter of the tree (Brute Force): " << d.diameterBruteForce(root) << endl;
//     cout << "Diameter of the tree (Optimal 1): " << d.diameterOfBinaryTree(root) << endl;
//     cout << "Diameter of the tree (Optimal 2): " << d.diameter(root) << endl;
//     return 0;
// }