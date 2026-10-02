#include "../buildTree.hpp"
#include<bits/stdc++.h>
using namespace std;

class RightSideView {
    public:
        // Time Complexity: O(N) where N is the number of nodes in the binary tree, as we visit each node once and perform constant time operations for each node.
        // Space Complexity: O(N) where N is the number of nodes in the binary tree, as we use a queue to perform level order traversal and store nodes at each level.
        vector<int> rightSideViewBFS(Node* root) {
            vector<int> ans;
            if(!root) return ans;

            queue<Node*> q; // Queue to perform level order traversal
            q.push(root); // Start with the root

            while(!q.empty()){
                int size = q.size(); // Number of nodes at the current level

                for(int i = 0; i < size; i++){
                    Node* node = q.front(); // Get the front node in the queue
                    q.pop();

                    // If this is the first node of the current level, add it to the answer
                    if(i == 0){
                        ans.push_back(node->data);
                    }

                    // Add left and right children to the queue for the next level
                    if(node->right) q.push(node->right);
                    if(node->left) q.push(node->left);
                }
            }

            return ans;
        }

        // Time Complexity: O(N) where N is the number of nodes in the binary tree, as we visit each node once and perform constant time operations for each node.
        // Space Complexity: O(H) where H is the height of the binary tree, as we use recursion and the maximum depth of the recursion stack is H.

        void RightSideViewDFS(Node* root, vector<int>& ans, int level) {
            if(!root) return;

            // If this is the first node of the current level, add it to the answer
            if(level == ans.size()){
                ans.push_back(root->data);
            }

            // Recur for left and right children, increasing the level
            RightSideViewDFS(root->right, ans, level + 1);
            RightSideViewDFS(root->left, ans, level + 1);
        }

        vector<int> rightSideView(Node* root) {
            vector<int> ans;
            RightSideViewDFS(root, ans, 0);
            return ans;

        }
};


int main(){
    
    Tree tree;
    Node* root = tree.buildTree(NULL);

    RightSideView rightSideViewObj;
    vector<int> result = rightSideViewObj.rightSideView(root);

    cout << "Right Side View of the Binary Tree: ";
    for(int val : result){
        cout << val << " ";
    }
    cout << endl;

    return 0;
}