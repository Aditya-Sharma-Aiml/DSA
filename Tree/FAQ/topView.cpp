#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class TopView {
    public:
    // tc -> O(NlogN) where N is the number of nodes in the binary tree, as we visit each node once and perform a logarithmic operation (insertion into the map) for each node.
    // sc -> O(N) where N is the number of nodes in the binary tree, as we store the top view nodes in a map and a vector.

        vector<int> topView(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            map<int, int> topNode; // Map to store the first node at each horizontal distance
            queue<pair<Node*, int>> q; // Queue to perform level order traversal, storing nodes along with their horizontal distances
            q.push({root, 0}); // Start with the root at horizontal distance 0

            while(!q.empty()){
                auto p = q.front(); // Get the front element of the queue
                q.pop();

                Node* node = p.first; // Current node
                int x = p.second; // Horizontal distance

                // If this is the first node at this horizontal distance, add it to the map
                if(topNode.find(x) == topNode.end()){
                    topNode[x] = node->data;
                }

                // Add left and right children to the queue with updated horizontal distances
                if(node->left) q.push({node->left, x-1});
                if(node->right) q.push({node->right, x+1});
            }

            // Collect the top view nodes from the map in order of their horizontal distances
            for(auto p: topNode){
                ans.push_back(p.second);
            }

            return ans;
        }

        // tc-> O(N) where N is the number of nodes in the binary tree, as we visit each node once and perform constant time operations for each node.
        // sc-> O(N) where N is the number of nodes in the binary tree, as we store the top view nodes in a map and a vector.
        
        vector<int> topViewOptimal(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            map<int, int> topNode; // Map to store the first node at each horizontal distance
            queue<pair<Node*, int>> q; // Queue to perform level order traversal, storing nodes along with their horizontal distances
            q.push({root, 0}); // Start with the root at horizontal distance 0

            int minHD = 0;
            int maxHD = 0;

            while(!q.empty()){
                auto p = q.front(); // Get the front element of the queue
                q.pop();

                Node* node = p.first; // Current node
                int x = p.second; // Horizontal distance

                // If this is the first node at this horizontal distance, add it to the map
                if(topNode.find(x) == topNode.end()){
                    topNode[x] = node->data;

                }

                // Add left and right children to the queue with updated horizontal distances
                if(node->left){

                    q.push({node->left, x-1});
                    minHD = min(minHD, x-1);

                }
                if(node->right){

                    q.push({node->right, x+1});
                    maxHD = max(maxHD, x+1);

                }
            }

            // Collect the top view nodes from the map in order of their horizontal distances
            for(int i = minHD; i <= maxHD; i++){
                ans.push_back(topNode[i]);
            }

            return ans;
        }

        
};
int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    TopView topViewObj;
    vector<int> result = topViewObj.topView(root);

    cout << "Top View of the Binary Tree:" << endl;
    for (int val : result) {

        cout << val << " ";
    }


    return 0;
}