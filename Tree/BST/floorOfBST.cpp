#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class FloorOfBST{
    public:
    // Approach: The floorOfBST function finds the largest value in a binary search tree (BST) that is less than or equal to a given target value. It uses a recursive approach to traverse the tree based on the properties of BST, where the left subtree contains values less than the root and the right subtree contains values greater than the root.
    // TC-> O(h) where h is the height of the binary search tree. In the worst case, we may need to traverse from the root to a leaf node.
    // SC-> O(1) as we are not using any additional data structures for storage.

    int floor(Node* root, int target) {
        int floor = -1; // Initialize floor to -1 (indicating no floor found)
        while (root) {
            if (root->data == target) {
                return root->data; // Exact match found, return the value
            }
            if (root->data < target) {
                floor = root->data; // Update floor to the current node's value
                root = root->right; // Move to the right subtree to find a larger value
            } else {
                root = root->left; // Move to the left subtree to find a smaller value
            }
        }
        return floor;
    }
};
