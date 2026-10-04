#include "../buildTree.hpp"
#include "nodeToNodePath.cpp"

#include<bits/stdc++.h>
using namespace std;
class LowestCommonAncestor {
    public:
        Node* getNode(Node* root, int value) {
            if (!root) return nullptr; // If the current node is null, return null

            if (root->data == value) return root; // If the current node matches the value, return it

            // Recursively search in the left and right subtrees
            Node* leftResult = getNode(root->left, value);
            if (leftResult) return leftResult; // If found in the left subtree, return it

            return getNode(root->right, value); // Otherwise, search in the right subtree
        }

    
        int lowestCommonAncestorBruteForce(Node* root, int node1, int node2) {
            NodeToNodePath nodeToNodePathObj;
            vector<int> path1 = nodeToNodePathObj.getPath(root, node1);
            vector<int> path2 = nodeToNodePathObj.getPath(root, node2);

            int lca = -1; // Initialize LCA to -1 (not found)
            int minLength = min(path1.size(), path2.size());

            for (int i = 0; i < minLength; i++) {
                if (path1[i] == path2[i]) {
                    lca = path1[i]; // Update LCA if nodes are the same
                } else {
                    break; // Stop when paths diverge
                }
            }

            return lca;
        }

        Node* lowestCommonAncestor(Node* root, Node* node1, Node* node2) {

            if(!root || root == node1 || root == node2) return root; // If root is null or matches one of the nodes, return root
            
            Node* left = lowestCommonAncestor(root->left, node1, node2);
            Node* right = lowestCommonAncestor(root->right, node1, node2);

            if(left && right) return root; // If both left and right are non-null, current node is LCA
            if(left == NULL )return right; // If left is null, return right (could be null or the found node)
            return left; // If right is null, return left (could be null or the found
        }

        
};

int main(){

    Tree tree;
    Node* root = tree.buildTree(NULL);

    NodeToNodePath nodeToNodePathObj;

    int n1, n2;
    cout << "Enter the values of the two nodes to find their LCA: ";
    cin >> n1 >> n2;

    LowestCommonAncestor lcaObj;

    Node* node1 = lcaObj.getNode(root, n1); // Replace with the actual value of node1
    Node* node2 = lcaObj.getNode(root, n2); // Replace with the actual value

    Node* lcaNode = lcaObj.lowestCommonAncestor(root, node1, node2);
    cout << "Lowest Common Ancestor of " << n1 << " and " << n2 << " is: ";
    if (lcaNode) {
        cout << lcaNode->data << endl;
    } else {
        cout << "None" << endl; // If LCA is not found
    }




}
