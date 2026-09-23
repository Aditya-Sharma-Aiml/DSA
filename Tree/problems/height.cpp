#include "../buildTree.hpp"
#include <bits/stdc++.h>
using namespace std;

class Height{
    public:

    int dfsHeight(Node* root){

        if(root == NULL) return 0; // Base case: If the node is NULL, the height is 0

        int lh = dfsHeight(root->left); // Recursive call to calculate the height of the left subtree
        int rh = dfsHeight(root->right); // Recursive call to calculate the height of the right subtree

        return max(lh, rh) + 1; // Return the maximum height between left and right subtrees, plus 1 for the current node

    }

    //level order traversal approach
    int bfsHeight(Node* root) {
        if (root == NULL) return 0; // Base case: If the node is NULL, the height is 0

        queue<Node*> q; // Create a queue to perform level order traversal
        q.push(root); // Start with the root node
        int height = 0; // Initialize height

        while (!q.empty()) {
            int size = q.size(); // Get the number of nodes at the current level
            for (int i = 0; i < size; i++) {
                Node* node = q.front(); // Get the front node in the queue
                q.pop(); // Remove it from the queue

                // Add left and right children to the queue if they exist
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            height++; // Increment height after processing all nodes at the current level
        }

        return height; // Return the final height of the tree
    }

};


// int main(){
//     Tree tree;
//     Node* root = tree.buildTree(NULL);

//     Height h;
//     cout << "Height of the tree (DFS): " << h.dfsHeight(root) << endl;
//     cout << "Height of the tree (BFS): " << h.bfsHeight(root) << endl;
//     return 0;
// }