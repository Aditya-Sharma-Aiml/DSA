#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class BottomView {
    public:
        vector<int> bottomView(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            map<int, int> bottomNode; // Map to store the first node at each horizontal distance
            queue<pair<Node*, int>> q; // Queue to perform level order traversal, storing nodes along with their horizontal distances
            q.push({root, 0}); // Start with the root at horizontal distance 0

            while(!q.empty()){
                auto p = q.front(); // Get the front element of the queue
                q.pop();

                Node* node = p.first; // Current node
                int x = p.second; // Horizontal distance

                // Update the bottom view node at this horizontal distance
                bottomNode[x] = node->data;
                

                // Add left and right children to the queue with updated horizontal distances
                if(node->left) q.push({node->left, x-1});
                if(node->right) q.push({node->right, x+1});
            }

            // Collect the top view nodes from the map in order of their horizontal distances
            for(auto p: bottomNode){
                ans.push_back(p.second);
            }

            return ans;
        }

        // tc-> O(N) where N is the number of nodes in the binary tree, as we visit each node once and perform constant time operations for each node.
        // sc-> O(N) where N is the number of nodes in the binary tree, as we store the bottom view nodes in a map and a vector.

        vector<int> bottomViewOptimal(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            map<int, int> bottomNode; // Map to store the first node at each horizontal distance
            queue<pair<Node*, int>> q; // Queue to perform level order traversal, storing nodes along with their horizontal distances
            q.push({root, 0}); // Start with the root at horizontal distance 0

            int minHD = 0;
            int maxHD = 0;

            while(!q.empty()){
                auto p = q.front(); // Get the front element of the queue
                q.pop();

                Node* node = p.first; // Current node
                int x = p.second; // Horizontal distance

                // Update the bottom view node at this horizontal distance
                bottomNode[x] = node->data;

                // Add left and right children to the queue with updated horizontal distances
                if(node->left) 
                {
                    q.push({node->left, x-1});
                    minHD = min(minHD, x-1);
                }
                if(node->right) 
                {
                    q.push({node->right, x+1});
                    maxHD = max(maxHD, x+1);
                }
            }

            // Collect the bottom view nodes from the map in order of their horizontal distances
            for(int i = minHD; i <= maxHD; i++){
                ans.push_back(bottomNode[i]);
            }

            return ans;
        }
};
int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    BottomView bottomViewObj;
    vector<int> result = bottomViewObj.bottomView(root);

    cout << "Bottom View of the Binary Tree:" << endl;
    for (int val : result) {

        cout << val << " ";
    }
    

    return 0;
}