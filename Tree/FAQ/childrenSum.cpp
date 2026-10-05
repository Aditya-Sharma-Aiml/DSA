#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class ChildrenSum{

    public:
    // Approach: The sum of all child nodes in a binary tree is the sum of the values of all nodes that have at least one child.
    // TC-> O(n) where n is the number of nodes in the binary tree. We visit each node once to calculate the sum of its child nodes.
    // SC-> O(h) where h is the height of the binary tree. The space complexity
    
    void sumOfChildNodes(Node* root){
        if(!root) return; // Base case: If the node is NULL, return 0

        int child = 0;
        if(root->left) child += root->left->data; // Add left child's data if it exists
        if(root->right) child += root->right->data; // Add right child's data if it exists

        if(child >= root->data) root->data = child; // If the sum of child nodes is greater than or equal to the current node's data, update the current node's data
        else{
            if(root->left) root->left->data = root->data; // If the left child exists, update its data to the current node's data
            if(root->right) root->right->data = root->data; // If the right child exists, update its data to the current node's data
        }

        sumOfChildNodes(root->left); // Recursively call for the left subtree
        sumOfChildNodes(root->right); // Recursively call for the right subtree

        int total = 0;
        if(root->left) total += root->left->data; // Add left child's data to total if it exists
        if(root->right) total += root->right->data; // Add right child's data

        if(root->left || root->right) root->data = total; // If the current node has at least one child, update its data to the total sum of child nodes


    }
     void printTree(Node* root) {
        if (!root) return;
        cout << root->data << " ";
        printTree(root->left);
        printTree(root->right);
    }
};
int main(){
    Tree t;
    Node* root = t.buildTree(NULL);

    ChildrenSum cs;
    cs.sumOfChildNodes(root);

    cout << "The binary tree after applying the children sum property is: " << endl;

    cs.printTree(root);
    cout << endl;

    return 0;

}