#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class CeilOfBST{
    public:
    // Approach: The ceilOfBST function finds the smallest value in a binary search tree (BST) that is greater than or equal to a given target value. It uses a recursive approach to traverse the tree based on the properties of BST, where the left subtree contains values less than the root and the right subtree contains values greater than the root.
    // TC-> O(h) where h is the height of the binary search tree. In the worst case, we may need to traverse from the root to a leaf node.
    // SC-> O(1) as we are not using any additional data structures for storage.

    int ceil(Node* root, int target) {
        int ceil = -1; // Initialize ceil to -1 (indicating no ceil found)
        while (root) {
            if (root->data == target) {
                return root->data; // Exact match found, return the value
            }
            if (root->data > target) {
                ceil = root->data; // Update ceil to the current node's value
                root = root->left; // Move to the left subtree to find a smaller value
            } else {
                root = root->right; // Move to the right subtree to find a larger value
            }
        }
        return ceil;
    }
};
