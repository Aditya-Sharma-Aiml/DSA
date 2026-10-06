#include "../../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Preorder{

    public:
    // Approach: The preorder traversal of a binary tree is a depth-first traversal where we visit the root node first, then recursively visit the left subtree, followed by the right subtree.
    // TC-> O(n) where n is the number of nodes in the binary tree. We visit each node once during the traversal.
    // SC-> O(1) where h is the height of the binary tree. The space complexity is due to the recursive call stack.

    void MorrisTraversal(Node* root, vector<int>& result) {
        
        Node* current = root; // Start with the root node

        while (current) {
            if (!current->left) {
                result.push_back(current->data); // Visit the current node
                current = current->right; // Move to the right child
            } else {
                Node* predecessor = current->left; // Find the inorder predecessor of the current node

                while (predecessor->right && predecessor->right != current) {
                    predecessor = predecessor->right; // Move to the rightmost node of the left subtree
                }

                if (!predecessor->right) {
                    result.push_back(current->data); // Visit the current node
                    predecessor->right = current; // Create a temporary link to the current node
                    current = current->left; // Move to the left child

                } else {
                    predecessor->right = nullptr; // Remove the temporary link
                    current = current->right; // Move to the right child
                }
            }
        }
    }

    vector<int> preorder(Node* root) {
        vector<int> result; // Vector to store the preorder traversal result
        MorrisTraversal(root, result); // Call the helper function to perform preorder traversal
        return result; // Return the result vector containing the preorder traversal
    }

};
int main(){
    Tree t;
    Node* root = t.buildTree(NULL);

    Preorder p;
    vector<int> result;
    result = p.preorder(root);
    cout << "Preorder traversal of the binary tree: ";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}