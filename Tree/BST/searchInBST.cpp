#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class SearchInBST{
    public:
    // Approach: The searchInBST function searches for a given value in a binary search tree (BST). It uses a recursive approach to traverse the tree based on the properties of BST, where the left subtree contains values less than the root and the right subtree contains values greater than the root.
    // TC-> O(h) where h is the height of the binary search tree. In the worst case, we may need to traverse from the root to a leaf node.
    // SC-> O(1) as we are not using any additional data structures for storage.

    Node* searchInBST(Node* root, int target) {
        if (!root) {
            return nullptr; // Base case: reached a null node, target not found
        }
        if (root->data == target) {
            return root ; // Target found
        }
        if (target < root->data) {
            return searchInBST(root->left, target); // Search in left subtree
        } else {
            return searchInBST(root->right, target); // Search in right subtree
        }
    }
    Node* search(Node* root, int target) {
        if(!root || root->data == target) {
            return root; // Base case: reached a null node or found the target
        }
        if(target < root->data) {
            return search(root->left, target); // Search in left subtree
        } else {
            return search(root->right, target); // Search in right subtree
        }
    }

};
