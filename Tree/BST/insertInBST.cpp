#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class InsertInBST{
    public:
    // Approach: The insertInBST function inserts a new value into a binary search tree (BST) while maintaining the properties of the BST. It uses a recursive approach to traverse the tree and find the appropriate position for the new value based on the properties of BST, where the left subtree contains values less than the root and the right subtree contains values greater than the root.
    // TC-> O(h) where h is the height of the binary search tree. In the worst case, we may need to traverse from the root to a leaf node.
    // SC-> O(1) as we are not using any additional data structures for storage.

    Node* insert(Node* root, int val) {
        if(!root) {
            return new Node(val); // If the current node is null, create a new node with the given value
        }

        Node* current = root; // Start with the root node
        while(current) {
            if(val >= current->data) {

                if(current->right){
                    current = current->right; // Move to the right child if it exists
                } else {
                    current->right = new Node(val); // Insert the new value as the right child
                    break; // Exit the loop after insertion
                }
                
            } else {
                
                if(current->left){
                    current = current->left; // Move to the left child if it exists
                } else {
                    current->left = new Node(val); // Insert the new value as the left child
                    break; // Exit the loop after insertion
                }
            }
        }
        return root;
    }
};