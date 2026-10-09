#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;
 // Tc-> O(h) where h is the height of the binary search tree. In the worst case, we may need to traverse from the root to a leaf node. 
 // if balanced tree then O(logn) and if skewed tree then O(n)

class DeleteNode{

    public:
    // Approach (Delete the Value): The deleteNode function removes a node with a given key from a binary search tree (BST) while maintaining the properties of the BST. It uses a recursive approach to traverse the tree and find the node to be deleted. If the node has two children, it finds the inorder successor (smallest value in the right subtree) to replace the deleted node's value. 

    Node* deleteNode(Node* root, int key) {
        if (!root) {
            return nullptr; // Base case: reached a null node, key not found
        }
        if (key < root->data) {
            root->left = deleteNode(root->left, key); // Search in left subtree
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key); // Search in right subtree

        } else {
            // Node to be deleted found
            if (!root->left) {
                Node* temp = root->right; // If no left child, return right child
                delete root; // Free memory of the current node
                return temp;

            } else if (!root->right) {
                Node* temp = root->left; // If no right child, return left child
                delete root; // Free memory of the current node
                return temp;

            } else {
                // Node has two children, find the inorder successor (smallest in the right subtree)
                Node* successor = root->right;
                while (successor->left) {
                    successor = successor->left; // Move to the leftmost node in the right subtree
                }
                root->data = successor->data; // Replace current node's data with successor's data
                root->right = deleteNode(root->right, successor->data); // Delete the inorder successor
            }
        }
        return root; // Return the updated subtree rooted at 'root'
    }

    //Approach (Iterative -> delete Actual node): The deleteNodeIterative function removes a node with a given key from a binary search tree (BST) using an iterative approach. It traverses the tree to find the node to be deleted and handles three cases: no children, one child, or two children. If the node has two children, it finds the inorder successor (smallest value in the right subtree) to replace the deleted node's value.
    Node* deleteNodeIterative(Node* root, int key) {
       
        if (!root) {
            return nullptr; // Base case: reached a null node, key not found
        }
        if(root->data == key) return helper(root); // If the root itself is the node to be deleted, call helper function

        Node* dummy = root; // Create a dummy pointer to traverse the tree
        while (root) {
            if (key < root->data) {
                if (root->left && root->left->data == key) {
                    root->left = helper(root->left); // If left child is the node to be deleted, call helper function
                    break;
                } else {
                    root = root->left; // Move to the left subtree
                }
            } else {
                if (root->right && root->right->data == key) {
                    root->right = helper(root->right); // If right child is the node to be deleted, call helper function
                    break;
                } else {
                    root = root->right; // Move to the right subtree
                }
            }
        }
        return dummy; // Return the updated tree rooted at 'dummy'
    }

    Node* helper(Node* root) {
        if (!root->left) {
            return root->right; // If no left child, return right child
        } else if (!root->right) {
            return root->left; // If no right child, return left child
        } else {
            Node* rightChild = root->right; // Store the right child
            Node* lastRight = findLastRight(root->left); // Find the rightmost node in the left subtree
            lastRight->right = rightChild; // Attach the original right subtree to the rightmost node of the left subtree
            return root->left; // Return the new root of the subtree (left child)
        }
    }

    Node* findLastRight(Node* root) {
        while (root->right) {
            root = root->right; // Move to the rightmost node
        }
        return root; // Return the rightmost node
    }
       
        
};