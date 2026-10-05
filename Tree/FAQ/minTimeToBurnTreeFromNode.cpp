#include "../buildTree.hpp"

#include <bits/stdc++.h>
using namespace std;

class MinTImeToBurnTreeFromNode{ 
    
    private:
    
    // Approach: 
        //1. Create a parent map to keep track of the parent of each node in the binary tree.
        //2. Perform a breadth-first search (BFS) starting from the target node, considering its left child, right child, and parent.
        //3. Keep track of the time taken to burn all nodes by counting the levels in the BFS traversal.
        //4. The maximum time taken to burn all nodes will be the answer.
        //5. Return the maximum time taken to burn all nodes in the binary tree.
        
        //tc -> O(n) where n is the number of nodes in the binary tree. We visit each node once to create the parent map and then perform BFS to find the minimum time to burn the tree.
        //sc -> O(n) where n is the number of nodes in the binary tree. The space complexity is due to the parent map and queue used for BFS.

    void createParentMap(Node* root, unordered_map<Node*, Node*>&parentMap, int target, Node* & targetNode){
        
        queue<Node*>q;
        q.push(root);
        
        while(!q.empty()){
            
            Node* curr = q.front();
            q.pop();
            
            if(curr->data == target) targetNode = curr; // If the current node's data matches the target, set targetNode to the current node
            
            if(curr->left){
                q.push(curr->left);
                parentMap[curr->left] = curr; // Map the left child to its parent (current node)
            }
            if(curr->right){
                q.push(curr->right);
                parentMap[curr->right] = curr; // Map the right child to its parent (current node)
            }
        }
    }
    
    int minTimeToBurn(Node* root, Node* targetNode, unordered_map<Node*, Node*>&parentMap){
        
        unordered_map<Node*, bool>vis; // To keep track of visited nodes during BFS     
        queue<Node*>q;
        
        int time  = 0;
        
        q.push(targetNode);
        vis[targetNode] = true;
        
        while(!q.empty()){
            
            int size = q.size(); // Number of nodes at the current level (distance from the target node)
            bool burned = false; // Flag to check if any node was burned at the current level
            
            for(int i=0; i<size; i++){
                
                Node* curr = q.front();
                q.pop();
                
                // Check left child
                if(curr->left && !vis[curr->left]){
                    vis[curr->left] = true;
                    q.push(curr->left);
                    burned = true;
                }
                //right child
                if(curr->right && !vis[curr->right]){
                    vis[curr->right] = true;
                    q.push(curr->right);
                    burned = true;
                }
                //up(parent)
                if(parentMap[curr] && !vis[parentMap[curr]]){
                    vis[parentMap[curr]] = true;
                    q.push(parentMap[curr]);
                    burned = true;
                }
            }
            
            if(burned) time++; // Increment time only if any node was burned at the current level
        }
        return time;
    }
  public:
    int minTime(Node* root, int target) {
        
        Node* targetNode = nullptr; // To store the pointer to the target node in the binary tree

        unordered_map<Node*, Node*>parentMap; // To keep track of parent nodes
        
        createParentMap(root, parentMap, target, targetNode); // Create the parent map and find the target node in the binary tree
        
        return minTimeToBurn(root, targetNode, parentMap); // Calculate the minimum time to burn the tree starting from the target node
    }
};

int main(){
    Tree t;
    Node* root = t.buildTree(NULL);

    int target;
    cout << "Enter the target node data: ";
    cin >> target;

    MinTImeToBurnTreeFromNode mt;
    int time = mt.minTime(root, target);

    cout << "Minimum time to burn the tree from node " << target << ": " << time << endl;

    return 0;
}