#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class NodeDistanceK{
    public:
    // Approach: 
        //1. map the parent of each node using a hash map for moving up the tree.
        //2. perform a breadth-first search (BFS) from the target node, considering the parent, left, and right children.
        //3. keep track of the distance from the target node and stop when the distance reaches K.
        //4. collect all nodes at distance K and return them.
        //5.remaining nodes in q will be at distance K from the target node.
        
        //tc -> O(n) where n is the number of nodes in the binary tree. We visit each node once to map parents and perform BFS.
        //sc -> O(n) where n is the number of nodes in the binary tree.


    void parentMap(Node* root, unordered_map<Node*, Node*>& parent_track) {
        if (!root) return; // Base case: If the node is NULL, return

        if (root->left) {
            parent_track[root->left] = root; // Map left child to its parent
            parentMap(root->left, parent_track); // Recur for left subtree
        }
        if (root->right) {
            parent_track[root->right] = root; // Map right child to its parent
            parentMap(root->right, parent_track); // Recur for right subtree
        }
    }
    
    vector<int> printNodesAtDistanceK(Node* root, Node* target, int k) {
        if (!root || !target || k < 0) return {}; // Edge case: If the root or target is NULL, or k is negative, return an empty vector 

        unordered_map<Node*, Node*>parent_track; // To keep track of parent nodes
        parentMap(root, parent_track); // Fill the parent map

        unordered_map<Node*, bool> visited; // To keep track of visited nodes
        queue<Node*> q; // Queue for BFS

        q.push(target); // Start BFS from the target node
        visited[target] = true; // Mark the target node as visited
        int distance = 0; // Initialize distance


        while(!q.empty() && k > 0) {
            int size = q.size();

            if(distance == k) {
                break; // If we have reached the desired distance, break the loop
            }
            distance++;

            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();

                // Check left child
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                }

                // Check right child
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                }

                // Check parent
                if (parent_track[current] && !visited[parent_track[current]]) {
                    visited[parent_track[current]] = true;
                    q.push(parent_track[current]);
                }
            }

        }
        vector<int> result; // To store the nodes at distance K
        while(!q.empty()) {
            result.push_back(q.front()->data);
            q.pop();
        }
        return result; // Return the result vector containing nodes at distance K

    }
    Node* findNode(Node* root, int targetData, Node* &targetNode) {
        if (!root) return nullptr; // Base case: If the node is NULL, return NULL

        if (root->data == targetData) {
            targetNode = root; // If the current node's data matches the target data, set targetNode
            return root; // Return the current node
        }

        // Recur for left and right subtrees
        Node* leftResult = findNode(root->left, targetData, targetNode);
        if (leftResult) return leftResult; // If found in left subtree, return it

        Node* rightResult = findNode(root->right, targetData, targetNode);
        return rightResult; // Return the result from the right subtree (could be NULL)
    }

};
        
int main(){

    Tree t;
    Node* root = t.buildTree(NULL);

    int targetData, k;
    cout << "Enter the target node data: "; 
    cin >> targetData;
    cout << "Enter the distance K: ";
    cin >> k;

    NodeDistanceK ndk;
    // Find the target node in the tree
    Node* targetNode = nullptr;
    targetNode= ndk.findNode(root, targetData, targetNode);

    if (!targetNode) {
        cout << "Target node not found in the tree." << endl;
        return 0; // Exit if the target node is not found
    }

    vector<int> nodesAtDistanceK = ndk.printNodesAtDistanceK(root, targetNode, k);
    cout << "Nodes at distance " << k << " from the target node: ";
    for (int node : nodesAtDistanceK) {
        cout << node << " "; // Print each node at distance K
    }
    cout << endl;

}