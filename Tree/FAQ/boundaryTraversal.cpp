#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class BoundaryTraversal {


    public:
        
        vector<int>boundaryTraversal(Node* root){

            if(!root) return {};
            vector<int>ans;

            // Add the root node to the answer if it is not a leaf node
            if(!isLeaf(root)) ans.push_back(root->data);

            //1. Add the left boundary nodes (excluding leaf nodes) to the answer
            //2. Add all the leaf nodes to the answer
            //3. Add the right boundary nodes (excluding leaf nodes) to the answer in reverse order
            addLeftBoundary(root, ans);
            addLeaves(root, ans);
            addRightBoundary(root, ans);

            return ans;
    
        }

    private:
        // Checks whether a node
        // has no children.

        bool isLeaf(Node* node) {
            return node != nullptr
                && node->left == nullptr
                && node->right == nullptr;
        }

        // Adds non-leaf nodes from the
        // left boundary in top-down order.
        void addLeftBoundary(Node* root, vector<int>& boundary
        ) {
            Node* current = root->left;

            // The outermost available child
            // continues the left boundary.
            while (current != nullptr) {
                // Leaves are collected separately,
                // so they are skipped here.
                if (!isLeaf(current)) {
                    boundary.push_back(current->data);
                }

                if (current->left != nullptr) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
        }

        // Collects all leaf nodes
        // from left to right.
        void addLeaves(Node* node, vector<int>& boundary
        ) {
            if (node == nullptr) {
                return;
            }

            // A leaf belongs directly
            // to the leaf section.
            if (isLeaf(node)) {
                boundary.push_back(node->data);
                return;
            }

            addLeaves(node->left, boundary);
            addLeaves(node->right, boundary);
        }

        // Adds the right boundary
        // in required bottom-up order.
        void addRightBoundary(Node* root, vector<int>& boundary
        ) {
            Node* current = root->right;
            vector<int> rightBoundary;

            // rightBoundary stores nodes top-down.
            // They are reversed for bottom-up order.
            while (current != nullptr) {
                // Leaves are collected separately,
                // so they are skipped here.
                if (!isLeaf(current)) {
                    rightBoundary.push_back(current->data   );
                }

                if (current->right != nullptr) {
                    current = current->right;
                } else {
                    current = current->left;
                }
            }

            // Reverse traversal places the
            // right boundary from bottom to top.
            for (
                int i = rightBoundary.size() - 1;
                i >= 0;
                i--
            ) {
                boundary.push_back(rightBoundary[i]);
            }
        }
};



int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    BoundaryTraversal BT;
    vector<int> result = BT.boundaryTraversal(root);
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }

    

    return 0;
}